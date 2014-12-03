#include <stdio.h>
typedef enum{
    FIRST,
    SECOND,
    THIRD,
}resp_type;

typedef struct{
    const char *name;
    resp_type response_type;
}response;

void func_first(response r){
    printf("In func_first, name is %s\n",r.name);
    return;
}

void func_second(response r){
    printf("In func_second, name is %s\n",r.name);
    return;
}

void func_third(response r){
    printf("In func_third, name is %s\n",r.name);
    return;
}

int main(){
    // Function ptr array and enum declared in same order as
    // FIRST which is 0, can be indexed into the func ptr array
    // for calling correct function.
    void (*func_responses[])(response) = {func_first, func_second, func_third};
    response r[] = { {"Sam",THIRD}, {"Mike",FIRST}, {"Dave",SECOND} };
    for( int i = 0; i <= 2; i++ ){
        (func_responses[r[i].response_type])(r[i]);
    }

    return 0;
}
