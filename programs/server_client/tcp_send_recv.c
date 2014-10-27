#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> // For internet address sockaddr_in ...
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcpio.h"

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
            printf("Connection closed by other party ...\n");
            break;
        }else if( byte_recv < 0 ){
            error("Recv Error");
        }else{
            total_byte_recv = total_byte_recv + byte_recv;
            temp_data_recv = temp_data_recv + byte_recv;
            if( data_recv[total_byte_recv - 1] == '\n' ){
                data_recv[total_byte_recv - 1] = '\0';
                puts("Hitting new line ... ");
                break;
            }
            data_recv[size - 1]='\0';
        }
    }
    return data_recv;
}

