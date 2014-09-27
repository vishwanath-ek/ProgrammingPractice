#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

void timesup(int sig){
    printf("Timesup !!! Game over ...\n");
    raise(SIGINT);
}

void ctrl_c(int sig){
    printf("Exiting ...\n");
    exit(1);
}

int mapSignalToHandler( int sig, void (*handler)(int) ){
    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = 0;
    sigemptyset(&(action.sa_mask));
    return sigaction(sig, &action, NULL);
}
void error(){
    fprintf(stderr, "Error %d: %s",\
    errno, strerror(errno));
    exit(1);
}

int main(){
    if( mapSignalToHandler(SIGALRM, timesup) ){ 
        error();
    }

    if( mapSignalToHandler(SIGINT, ctrl_c) ){
        error();
    }

    srandom(time(NULL));
    struct itimerval timer;
    memset(&timer,sizeof(struct itimerval),0);
    
    int score = 0;
    while(1){
        int a = (int)random()%19;
        int b = (int)random()%21; 
        printf("You get 15 seconds .... What is %d * %d ...\n",\
        a, b);
        
        timer.it_interval.tv_sec=0;
        timer.it_interval.tv_usec=0;
        timer.it_value.tv_usec = 0;
        timer.it_value.tv_sec = 16;
        // Or time.h has alarm(16); giving 1 sec extra...
        if( setitimer(ITIMER_REAL, &timer, NULL) ){
            error();
        }

        char ans[5];
        fgets(ans,5,stdin);
        int answer = atoi(ans);
        if( answer == a*b ){
            score++;
            printf("Score is %d ...\n", score);
        }else{
            printf("Wrong !!! Score is %d ...\n", score);
        }
    }

    return 0;
}
