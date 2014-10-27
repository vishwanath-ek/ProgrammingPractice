#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> // For internet address sockaddr_in ...
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 512

void
error( const char *msg ){
    fprintf(stderr, "%s -> %d: %s\n", msg, errno, strerror(errno));
    exit(1);
}

int 
say(int socket_send, const char *msg){
    if( send(socket_send, msg, strlen(msg), 0) == -1 ){
        error("Send Error");
    }

    return 0;
}

char *
accept_data(int child_socket){
    char *data_recv = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    int size = BUFFER_SIZE;
    memset(data_recv, 0, BUFFER_SIZE);
    int total_byte_recv = 0;    
    char *temp_data_recv = data_recv;
    while(1){
        int byte_recv = recv(child_socket, temp_data_recv, size - total_byte_recv, 0);
        printf("byte_recv %d, total_byte_recv %d\n", byte_recv, total_byte_recv);
        if( byte_recv == 0 ){
            printf("Connection closed by client ...\n");
            break;
        }else if( byte_recv < 0 ){
            error("Recv Error");
        }else{
            total_byte_recv = total_byte_recv + byte_recv;
            temp_data_recv = temp_data_recv + byte_recv;
            if( data_recv[total_byte_recv - 1] == '\n' ){
                data_recv[total_byte_recv - 2] = '\0';
                puts("Hitting new line ... ");
                break;
            }
            data_recv[size - 1]='\0';
        }
    }
    return data_recv;
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
            say(child_socket, "Hi, You are connected ... Please enter the file path ...\n");
            char *data_recv = accept_data(child_socket);
            printf("Data Got from client: %s\n",data_recv);
            free(data_recv);
            close(child_socket);
            exit(0);
        }
        close(child_socket);
    }

    return 0;
}
