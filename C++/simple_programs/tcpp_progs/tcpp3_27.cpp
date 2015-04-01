#include <iostream>

int main(){
    const int constDoubleArr[5] = {0, 0, 0, 0, 0} ;
    volatile int volDoubleArr[5] ;

    for(int i = 0; i < 5; i++){
        int *addr = const_cast<int *>(&constDoubleArr[i]) ;
        *addr = i;
        addr = const_cast<int *>(&volDoubleArr[i]) ;
        *addr = i+1;
    }

    return 0;
}
