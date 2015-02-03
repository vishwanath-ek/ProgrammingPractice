#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

int
main(){
    int *int_ptr = new int;
    *int_ptr = 10;

    long *long_ptr = new long;
    *long_ptr = 20L;

    char *char_ptr = new char[100];
    memset(char_ptr, 0, 100);

    printf("Address of int -> %p\n", int_ptr);
    printf("Address of long -> %p\n", long_ptr);
    printf("Address of char array -> %p\n", char_ptr);

    delete int_ptr;
    delete long_ptr;
    delete char_ptr;

    return 0;
}
