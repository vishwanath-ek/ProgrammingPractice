#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef enum {
    ONE,
    TWO,
    THREE,
}NUMBER;

int main(int argc, char **argv) {
    int i = 1;
    char **newArgvCopied = (char **)malloc(sizeof(char *) * argc);
    if( !newArgvCopied ){
        perror("Malloc failed.");
        exit(-1);
    }
    memset(newArgvCopied, 0, sizeof(char *) * argc);

    char **tempNewArgv = newArgvCopied;
    for(i = 0; i < argc - 1; i++) {
        memcpy(tempNewArgv, argv+1, sizeof(char *));
        ++tempNewArgv;
        ++argv;
    }

    for(i = 0; i< argc - 1; i++) {
        printf("%d: %s\n",i , newArgvCopied[i]);
    }

    return 0; 
}
