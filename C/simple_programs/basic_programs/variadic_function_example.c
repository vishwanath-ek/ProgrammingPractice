#include <stdio.h>
#include <stdarg.h>
// Variadic functions can take variable number of arguments.
// Use of MACROS: va_start, va_end & va_arg.
// Use of Ellipsis (...) to indicate variable args.
void print_ints_with_name(char *name, int num, ...){
    va_list list_param;
    va_start(list_param, num); // num is the LAST FIXED PARAM !!!

    int i;
    printf("Name: %s\n",name);
    for(i = 0; i < num; i++){
        printf("\tArg%d: %i\n", i, va_arg(list_param,int) );
    }

    va_end(list_param);
}

int main(){
    print_ints_with_name("First Call",3,10,20,30);
    print_ints_with_name("Second Call",6,10,11,12,13,14,15);

    return 0;
}
