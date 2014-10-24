#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

void
error( const char *msg ){
    fprintf(stderr, "%s -> %d: %s\n", msg, errno, strerr(errno));
    exit(1);
}

int 
main(){
    int parent_socket = socket(PF_INET, SOCK_STREAM, 0);
    if( parent_socket == -1 ){
        error("Error in socket creation");
    }

    return 0;
}    
