#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> // For internet address sockaddr_in ...
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "tcpio.h"
#include <signal.h>

void
error( const char *msg ){
    fprintf(stderr, "%s -> %d: %s\n", msg, errno, strerror(errno));
    exit(1);
}

int 
say(int socket_send, const char *msg){
    char_struct *data_send = (char_struct *)malloc(sizeof(char_struct));
    strncpy(data_send->data, msg, sizeof(data_send->data));
    data_send->size = strlen(msg);
    if( send(socket_send, (char *)data_send, sizeof(char_struct), 0) == -1 ){
        error("Send Error");
    }
    free((void *)data_send);
    return 0;
}

char_struct *
accept_data(int child_socket){
    char_struct *data_recv = (char_struct *)malloc(sizeof(char_struct));
    memset(data_recv, 0, sizeof(char_struct));
    int byte_recv = recv(child_socket, data_recv, sizeof(char_struct), 0);
//    printf("byte_recv %d\n", byte_recv);
    if( byte_recv == 0 ){
        printf("Connection closed by other party ...\n");
        return NULL;
    }else if( byte_recv < 0 ){
        error("Recv Error");
    }

    return data_recv;
}

// Function to register handler(func passed) to OS
int
catch_signal(int signal, void (*handler)(int)){
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    return sigaction(signal, &action, 0);
}

void
free_data_recv(void *data){
    if( data != NULL ){
        free(data);
    }
    return;
}
