#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
/* This Program takes three arguments f for flag(n oargs required),
 * c for count(args required) and d for delivery address address
 * args required.
 */
int main(int argc, char *argv[]){
    char *delivery_addr = NULL;
    int count = 0;
    int flag = 0;

    char arg = '\0';
    // : implies that arguments are required following the option.
    while( (arg = getopt(argc,argv,"fd:c:")) != EOF ){
        switch(arg){
            case 'f':
                flag = 1;
                break;
            case 'c':
                count = atoi(optarg);
                break;
            case 'd':
                // optarg is a char pointer to the argument of the option.
                delivery_addr = optarg; 
                break;
            default:
                fprintf(stderr,"Invalid option found\n\
Allowed options are f,c, & d\n");
                return 10;
        }
    }

    // optind stores the number of strings read from cmdline, to get past them
    // add optind to argv and subtract optind from argc.
    argc -= optind;
    argv += optind;
    if(count){
        printf("The count received is: %d\n",count);
    }
    if(flag){
        printf("Flag is: %d\n",flag);
    }
    if(delivery_addr){
        printf("Delivery address is: %s\n",delivery_addr);
    }

//    printf("Argc and optind %d & %d\n",argc,optind);

    if( argc ){ // There are extra arguments ... if you want to understand print argc and optind.
        puts("Remaining arguments:");
    }
    for(count = 0; count<argc; count++){
        printf("Argv[%d] is %s\n",count,argv[count]);
    }

    return 0;
}
