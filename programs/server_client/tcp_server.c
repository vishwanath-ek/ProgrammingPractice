#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> // For internet address sockaddr_in ...
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h> // For directory listing
#include "tcpio.h"

static char *files[512]; //Considering only 512 files are there ...

void
get_directory_listing(const char *path){
    DIR *dir;
    struct dirent *ent;
    int index = 0;
    if ( (dir = opendir(path)) != NULL ){
          /* print all the files and directories within directory */
        while ( (ent = readdir(dir)) != NULL ){
            //printf ("%s\n", ent->d_name);
            if( index <= 512 ){
                if( !strchr(ent->d_name, '~') && strncmp(ent->d_name, ".", 1) && strncmp(ent->d_name, "..", 2) ){
                    files[index++] = ent->d_name;
                }
            }
        }
        closedir (dir);
    }else{
          /* could not open directory */
        error ("Directory Open Error");
    }

    return;
}

int 
main(){
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
    while(1){
        puts("Waiting at accept system call ... Awaiting client requests ... ");
        int child_socket = accept(parent_socket, (struct sockaddr *)&client_addr, &addr_len);
        if( child_socket == -1 ){
            error("Accept Error");
        }
        if( !fork() ){
            close(parent_socket);
            say(child_socket, "Hi, You are connected ... Please enter the file path ...");
            get_directory_listing("/home/vishwanath/Documents");
            int index = 0;
            while( index < 513 && files[index] != NULL ){
//                printf("index: %d, %s\n", index, files[index]);
                index++;
            }

            char char_num_files[4];
            sprintf(char_num_files,"%d", index);
            char_num_files[3]='\0'; 

            say(child_socket, char_num_files);

            char_struct *data_recv = accept_data(child_socket);
            if(data_recv->size != 0){
                printf("Data Got from client: %s\n",data_recv->data);
            }
            if( data_recv ){
                free((void *)data_recv);
            }
            close(child_socket);
            exit(0);
        }
        close(child_socket);
    }

    return 0;
}
