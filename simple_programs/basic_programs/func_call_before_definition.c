#include <stdio.h>

int main(){
    int x = func_call();
    //float x = func_call();
    printf("Success returning int \n");
    //printf("Failure returning float \n");
    return 0;
}
// If func is called before defining, the compiler makes a note of the function and assumes
// it will return an int.

int func_call(){
    return 2;
}

