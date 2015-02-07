#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <signal.h>
#include <assert.h>
#include "linkedListFunc.h"

static Node *HEAD = NULL;
char *buffer = NULL;
static pthread_mutex_t buffer_mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t read_flag_one = PTHREAD_COND_INITIALIZER;
static pthread_cond_t read_flag_zero = PTHREAD_COND_INITIALIZER;
static short read_flag = 0;
static short fin_flag = 0;
uint16_t count = 0;

void
error(const char *msg){
    fprintf(stderr, "%s\n%s (ERRNO: %d)\n", msg,\
    strerror(errno), errno);
    exit(errno);
}

int
catchSignal(int signal, void (*handler) (int)){
    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = 0;
    sigemptyset(&(action.sa_mask));
    return sigaction(signal, &action, NULL);
}

void
sigIntHandler(int signal){
    (void)signal; // To prevent unused variable warnings
    fin_flag = 1;
    fprintf(stdout,"Caught SIGINT ... gracefully quitting ... Bye !!!\n\n\n\n\n");
    return ;
}

Node *
traverseListTillNextNull(){
    Node *n = HEAD;
    while( n->next ){
        n = n->next;
    }
    return n;
}

void *
readFunc(void *arg){
    (void)arg; // To prevent compiler warning
    FILE *file = fopen(FILE_FULL_PATH, "r");
    if( !file ){
        error("fopen error.");
    }

    while(1){
        pthread_mutex_lock(&buffer_mutex);
        if(fin_flag == 1){
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        while( read_flag ){
            pthread_cond_wait(&read_flag_one, &buffer_mutex);
        }
        if(fin_flag == 1){
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        memset(buffer, 0, BUFFER_SIZE);
        if( fgets(buffer, BUFFER_SIZE, file) != NULL ){
            read_flag = 1;
            pthread_cond_signal(&read_flag_zero);
        }else{
            fin_flag = 1;
            pthread_cond_signal(&read_flag_zero);
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        pthread_mutex_unlock(&buffer_mutex);
    }
    fclose(file);
    pthread_exit((void *)1);
}

void *
addToList(void *arg){
    (void)arg; // To prevent compiler warning
    while(1){
        pthread_mutex_lock(&buffer_mutex);
        if( fin_flag ){
            pthread_mutex_unlock(&buffer_mutex);
            break; 
        }
        while( !fin_flag && !read_flag ){
            pthread_cond_wait(&read_flag_zero, &buffer_mutex);
        }
        if( fin_flag ){
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        count++;
        Node *n = (Node *)malloc(sizeof(Node));
        memset((char*)n, 0, sizeof(Node));
        strncpy(n->file_data, buffer, strlen(buffer));
        n->next = NULL;
        if( count == 1 ){
            HEAD = n;
        } else {
            Node *node_ptr = traverseListTillNextNull();
            node_ptr->next = n;
        }
        read_flag = 0;
        pthread_cond_signal(&read_flag_one);
        pthread_mutex_unlock(&buffer_mutex);
    }

    pthread_exit((void *)1);
}

void
freeLinkedList(){
    Node *n = HEAD;
    while( n ){
        Node *tmp = n;
        n = n->next;
        free(tmp);
    }
}

void
printList(){
    assert(HEAD != NULL);
    fprintf(stdout,"Inside PrintList ...\n");
    Node *n = HEAD;
    while( n ){
        Node *tmp = n;
        n = n->next;
        fprintf(stdout,"%s",tmp->file_data);
    }

    return;
}

int
main(){
    if( catchSignal(SIGINT, sigIntHandler) == -1){
        error("Error in catchSignal.");
    }

    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    memset(buffer, 0, BUFFER_SIZE);

    pthread_t read_thread;
    pthread_t add_to_list_thread;

    if( (pthread_create(&read_thread, 0, readFunc, NULL) == -1) || \
        (pthread_create(&add_to_list_thread, 0, addToList, NULL) == -1) ){
        error("pthread create error.");
    }

    void *result = NULL;
    if( pthread_join(read_thread, &result) == -1 ){
        error("pthread join error.");
    }
    if( pthread_join(add_to_list_thread, &result) == -1 ){
        error("pthread join error.");
    }

    printList();
    freeLinkedList();
    free(buffer);
    pthread_mutex_destroy(&buffer_mutex);

    return 0;
}
