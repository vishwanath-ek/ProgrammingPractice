#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
} NUMBER;

typedef union {
    int a;
    char c;
    double d;
} UNION;

typedef void (*funcPtr)(NUMBER, UNION);
void someFunc(NUMBER, UNION);

int main(){
    UNION union1;
    union1.d = 2.18;
    printf("union1: %f\n", union1.d);

    UNION union2 = {2};
    printf("union2: %d\n", union2.a);

    UNION union3 = {.c = 'a'};
    printf("union3: %c\n", union3.c);

    NUMBER num2 = THREE;
    
    funcPtr someFuncPtr = someFunc;

    someFuncPtr(num2, union3);

    char *someCharPtr = "This is vishwanath";
    char *destPtr = (char *)malloc((strlen(someCharPtr) + 1) * sizeof(char));
    memset(destPtr, 0, (strlen(someCharPtr) + 1));
    strncpy(destPtr, someCharPtr, strlen(someCharPtr));
    destPtr[strlen(someCharPtr) + 1] = '\0';

    printf("Copied value: %s\n", destPtr);
    // NOTE unsigned short below.
    printf("Value of strcmp: %hu\n", strncmp(someCharPtr, destPtr, strlen(destPtr)));

    char *concatPtr = (char *)calloc(strlen(destPtr)*2 + 1, sizeof(char));
    strcat(concatPtr, destPtr);
    printf("First concat: %s\n", concatPtr);
    strcat(concatPtr, someCharPtr);
    printf("Second concat: %s\n", concatPtr);

    free(destPtr);
    free(concatPtr);

    return 1;
}

void someFunc(NUMBER num, UNION uni){
    printf("--------- INSIDE FUNC ---------\n");
    printf("Number and union is: %d - %c\n", num, uni.c);
}
