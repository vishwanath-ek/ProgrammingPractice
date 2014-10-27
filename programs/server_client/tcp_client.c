#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
/* For domain name services ... find IP from domain ...
 * contains function getaddrinfo that creates a named resource
 * containing the information about the IP address.
 */                    
#include <netdb.h>
#include <stdlib.h>
#include "tcpio.h"

/* Bind the server remote port to the socket for connect ...
 * Need to know the server IP address and PORT to connec to.
 */
struct sockaddr_in *
use_direct_bind_ip(){
    struct sockaddr_in *client_sockaddr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    client_sockaddr->sin_family = PF_INET;
    client_sockaddr->sin_port = htons(30000);
    client_sockaddr->sin_addr.s_addr = inet_addr("127.0.0.1");

    return client_sockaddr;
}

int
main(){
    int client_socket = socket(PF_INET, SOCK_STREAM, 0);
    if( client_socket == -1 ){
        error("Socket creation");
    }
    
//    use_getaddrinfo_bind();
    const struct sockaddr_in *remote_sockaddr = (const struct sockaddr_in *)use_direct_bind_ip();
    int conn_val = connect(client_socket, (struct sockaddr *)remote_sockaddr, sizeof(struct sockaddr_in));
    if( conn_val == -1 ){
        error("Connect Error");
    }

    say(client_socket, "This is a message sent from client ...\n");

    return 0;
}
