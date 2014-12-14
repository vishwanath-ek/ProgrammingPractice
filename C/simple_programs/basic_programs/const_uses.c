#include <stdio.h>
int main(){
    const int i = 10; // This is assign i to 10;
//    i = 12; // Compile Error as i is const;

    const int *p = &i; // const int -> data constant (const is left of *)
    (*p)++ ; // Compilation error.

/*    
    int z = 30;
    int y = 20;
    int * const x = &z; // const x -> pointer constant (const to right of *)
    x = &y; // Compile error.
*/
    return 0;
}
