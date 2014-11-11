#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> // For internet address sockaddr_in ...
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h> // For directory listing
#include "tcpio.h"
#include <sys/stat.h> // For getting file info using stat function
#include <signal.h>
#include <pthread.h>

static char *files[NUM_OF_FILES]; //Considering only 512 files are there in tcpio.h ...
static char filedata_buffer[512];
short read_flag = 0;
short null_flag = 0;
short continue_flag = 1;

pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_read_cond = PTHREAD_COND_INITIALIZER;
pthread_cond_t buffer_write_cond = PTHREAD_COND_INITIALIZER;

static void
sigint_handler(void){
    printf("Caught sigint...\nSetting main func. break\n");
    continue_flag = 0;
}

static int
is_regular_file(const char *file_name){
    struct stat info;
    char full_path[500];

    get_full_path(full_path, file_name);
    if( stat(full_path, &info) ){
        error("STAT error");
    }

    if( S_ISREG(info.st_mode) ){
        return 1;
    }

    return 0;
}

static void
get_directory_listing(const char *path){
    DIR *dir;
    struct dirent *ent;
    int index = 0;
    if ( (dir = opendir(path)) != NULL ){
          /* traverse all the files and directories within directory */
        while ( (ent = readdir(dir)) != NULL ){
            //printf ("%s\n", ent->d_name);
            if( index < NUM_OF_FILES ){
          //      if( !strchr(ent->d_name, '~') && strncmp(ent->d_name, ".", 1) && strncmp(ent->d_name, "..", 2) ){
                if( is_regular_file(ent->d_name) ){
                    files[index] = (char *)malloc(strlen(ent->d_name)*sizeof(char) + 1);
                    memset(files[index], 0, strlen(ent->d_name)*sizeof(char) + 1);
                    strncpy(files[index], ent->d_name, strlen(ent->d_name));
                    index++;
                }
            }
        }
        closedir(dir);
    }else{
          /* could not open directory */
        error ("Directory Open Error");
    }

    return;
}

static int
get_num_of_files(){
    int index = 0;
    while( index < NUM_OF_FILES && files[index] != NULL ){
//        printf("index: %d, %s\n", index, files[index]);
        index++;
    }
    return index;
}

static void
send_all_files(int child_socket, int num_of_sends){
    int count = 0;
//    int fin_flag = 0;
    printf("Send all files num_of_sends %d\n", num_of_sends);
    while( count < num_of_sends ){
        if( files[count] ){
            printf("sending %s...\n", files[count]);
        }
        say(child_socket, files[count]);
        count++;
        char_struct *data_recv = accept_data(child_socket);
        free_data_recv(data_recv);
    }
    return;
}

static unsigned int
check_file_present(char *file_name){
    unsigned int index = 0;
    while( index < NUM_OF_FILES && files[index] != NULL ){
        if( strncmp(files[index], file_name, strlen(files[index])) == 0 ){
            free((void *)files[index]);
            return 1;
        }
        free((void *)files[index]);
        index++;
    }

    return 0;
}

static void *
thread_read(void *arg){ 
    const char *file_name = (const char *)arg;
    fprintf(stdout, "Filename received is %s\n",file_name);
    char *file_path = (char *)malloc(512 * sizeof(char));
    file_path = get_full_path(file_path, file_name);
    FILE *fd = fopen(file_path,"r");
    if( (fd) == NULL){
        error("File open error");
    }
    while( 1 ){
         pthread_mutex_lock(&buffer_mutex);
         while( read_flag == 1 ){
             pthread_cond_wait(&buffer_write_cond, &buffer_mutex);
         }
         if(fgets(filedata_buffer, sizeof(filedata_buffer), fd)){
             read_flag = 1;
             pthread_cond_signal(&buffer_read_cond);
             fprintf(stdout, "!!!After Read!!!%s", filedata_buffer);
         }else{
             read_flag = 1;
             null_flag = 1;
             pthread_cond_signal(&buffer_read_cond);
         }
         pthread_mutex_unlock(&buffer_mutex);
         if( null_flag ){
             break;
         }
    }

    free((void *)file_path);
    fclose(fd);
    fprintf(stdout, "Read thread exit\n");

    pthread_exit((void *)1);
}

static void *
thread_send(void *arg){
    int child_socket = (int)arg;
    while( 1 ){
        pthread_mutex_lock(&buffer_mutex);
        while( read_flag == 0 ){
            if(null_flag){
                pthread_mutex_unlock(&buffer_mutex);
                break;
            }
            pthread_cond_wait(&buffer_read_cond, &buffer_mutex);
        }
        if(null_flag){
            say(child_socket, "!@FINISHED TRANSFER@!");
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        //fprintf(stdout, "***Instead of send***%s", filedata_buffer);
        say(child_socket, (const char *)filedata_buffer);
        free_data_recv(accept_data(child_socket));
        read_flag = 0;
        pthread_cond_signal(&buffer_write_cond);        
        pthread_mutex_unlock(&buffer_mutex);
    }
    fprintf(stdout, "Send thread exit\n");

    pthread_exit((void *)1);
}

static void
create_thread_read_file_transfer(const char *file_name, int child_socket){
    pthread_t thread_read_id;
    pthread_t thread_read_send_id;

    pthread_create(&thread_read_id, 0, thread_read, (void *)file_name);
    pthread_create(&thread_read_send_id, 0, thread_send, (void *)child_socket);

    void *result = NULL;
    pthread_join(thread_read_id, &result);
    pthread_join(thread_read_send_id, &result);

    return;
}

int
main(){
    if( catch_signal(SIGINT, sigint_handler) == -1 ){
        error("Registering signal handler");
    }
    int parent_socket = socket(PF_INET, SOCK_STREAM, 0);
    if( parent_socket == -1 ){
        error("Error in socket creation");
    }

    int reuse = 1;
    if( setsockopt(parent_socket, SOL_SOCKET, SO_REUSEADDR,\
        (char *)&reuse, sizeof(int)) == -1 ){
        error("SETSOCKOPT Error");
    }

    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_port = (in_port_t)htons(30000);
    server_sockaddr.sin_family = PF_INET;
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if( bind(parent_socket, (struct sockaddr *)&server_sockaddr,\
        sizeof(struct sockaddr_in)) == -1 ){
        error("Bind Error");
    }

    if( listen(parent_socket, 2) == -1 ){
        error("Listen Error");
    }

    struct sockaddr_storage client_addr;
    unsigned int addr_len = sizeof(struct sockaddr_storage);
    while(continue_flag){
        puts("Waiting at accept system call ... Awaiting client requests ... ");
        int child_socket = accept(parent_socket, (struct sockaddr *)&client_addr, &addr_len);
        if( child_socket == -1 && continue_flag){
            error("Accept Error");
        }
        if(!continue_flag){
            break;
        }
        if( !fork() ){
            close(parent_socket);

            free_data_recv(accept_data(child_socket));
            say(child_socket, "Hi, You are connected ... Please enter the file path ...");
            free_data_recv(accept_data(child_socket));

            get_directory_listing(SHARE_FILES_PATH);
            int index = get_num_of_files();
            char char_num_files[4];
            sprintf(char_num_files,"%d", index);
            char_num_files[3]='\0'; 
             
            say(child_socket, char_num_files);
            free_data_recv(accept_data(child_socket));

            send_all_files(child_socket, index);

            char_struct *data_recv = accept_data(child_socket);
            if(data_recv->size != 0){
                printf("Data Got from client: %s\n",data_recv->data);
            }
            char *file_name_recv = (char *)malloc(strlen(data_recv->data) + 1);
            memset(file_name_recv, 0, strlen(data_recv->data) + 1);
            strncpy(file_name_recv, data_recv->data, strlen(data_recv->data));
            free_data_recv(data_recv);

            if( !check_file_present(file_name_recv) ){
                say(child_socket, "WRONG FILE NAME");
                fprintf(stderr,"Filename entered not present ...\n");
                free_data_recv(file_name_recv);
                exit(1);
            }

            say(child_socket, (const char *)file_name_recv);
            free_data_recv(accept_data(child_socket));
            create_thread_read_file_transfer(file_name_recv, child_socket); 
            free_data_recv(file_name_recv);

            printf("Closing Child Socket ...\n");
            pthread_mutex_destroy(&buffer_mutex);
            pthread_cond_destroy(&buffer_read_cond);
            pthread_cond_destroy(&buffer_write_cond);
            close(child_socket);
            exit(0);
        }
        close(child_socket);
    }
    pthread_mutex_destroy(&buffer_mutex);
    pthread_cond_destroy(&buffer_read_cond);
    pthread_cond_destroy(&buffer_write_cond);

    close(parent_socket);

    return 0;
}
