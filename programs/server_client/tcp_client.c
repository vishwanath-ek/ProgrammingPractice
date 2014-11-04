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
#include <unistd.h>
#include <string.h>
/* Bind the server remote port to the socket for connect ...
 * Need to know the server IP address and PORT to connec to.
 */
static struct sockaddr_in *
use_direct_bind_ip(){
    struct sockaddr_in *client_sockaddr = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
    client_sockaddr->sin_family = PF_INET;
    client_sockaddr->sin_port = htons(30000);
    client_sockaddr->sin_addr.s_addr = inet_addr("127.0.0.1");

    return client_sockaddr;
}

static void
recv_and_display_all_files(int client_socket, int num_of_files){
    int count = 1; 
    while( count <= num_of_files ){
        char_struct *data_recv = accept_data(client_socket);
        if(data_recv->size != 0){
            printf("%d. %s\n", count, data_recv->data);
        }
        free_data_recv(data_recv);
        count++;
        say(client_socket, "Send next");
    }
    return;
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

    say(client_socket, "Starting to receive ...");
    char_struct *data_recv = accept_data(client_socket);
    if(data_recv->data[data_recv->size] == '\0'){
        printf("%s\n",data_recv->data);
    }
    free_data_recv(data_recv);

    say(client_socket, "Got data");

    data_recv = accept_data(client_socket);
    int num_of_files = atoi(data_recv->data); 
//    printf("Number of files at server: %d\n", num_of_files); 
    free_data_recv(data_recv);

    say(client_socket, "Start send");

    recv_and_display_all_files(client_socket, num_of_files);

    puts("\nPlease enter a file name from the above list:");
    char *file_name = (char *)malloc(sizeof(char)*50);
    bzero(file_name,sizeof(char)*50);
    fgets(file_name, sizeof(char)*50, stdin);
    file_name[strlen(file_name)-1]='\0';
    printf("Entered file name: %s\n", file_name);
    say(client_socket, file_name);
    free_data_recv(file_name);

    close(client_socket);
    free((void *)remote_sockaddr);

    return 0;
}
