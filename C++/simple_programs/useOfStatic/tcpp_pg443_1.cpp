#include <iostream>
using std::cout; using std::endl;

int
returnNextElement(int *arg = NULL){
    static int *ptr = NULL;
    if(arg){
        ptr = arg;
        if( *ptr == -1 ){

        }
        return *ptr;
    }
    ptr += 1;

    if(*ptr == -1){
        return (-65535);
    }
    return *ptr;
}

int
main(int argc, char **argv){
    (void)argc;
    (void)argv;
    int a[]={1, 2, 0, 2, 111, -65532, -1, 0, 2, 4};
    
    cout << returnNextElement(a) << endl;
    int c = 0;
    while(1){
        cout << (c = returnNextElement()) << endl;
        if(c == -65535){
            break;
        }
    }

    return 1;
}
