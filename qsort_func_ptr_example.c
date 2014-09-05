#include <stdio.h>
#include <stdlib.h> // For qsort
// qsort comparator function (func pointer used to call) 
// prototype is: int (*match)(const void *, const void *)
int compare_integers(const void *a, const void *b){
    int first = *((int *)a);
    int second = *((int *)b);

    return (first - second);
// first - second gives ascending ouput
// second - first descending
}
// Can also write a function to sort strings on alphabetical ordering
// use: strcmp and (char *) typecasting & return similar concept 
// strcmp value.

int main(){
    // first_array address of first variable.
    int size_first_array = 7; 
    int first_array[]={2,3,-1,0,10,2,-10};
    qsort((void *)first_array, size_first_array, sizeof(int), compare_integers);
    for(int i = 0; i < size_first_array; i++){
        printf("%d ",first_array[i]);
    }
    puts("");

    return 0;
}

