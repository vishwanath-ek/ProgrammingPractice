#include <iostream>
using std::cout; using std::endl;

int
fibonacci(bool flag = false){
    static int c = 0;
    static int a = 1, b = 1;
    if( flag == true ){
        c = 0; 
        a = b = 1;
        return -1;
    }

    c = a + b;
    a = b;
    b = c;

    return a;
}

int
main(){
    int i = -1; 
    while( (++i) != 20){
        cout << fibonacci() << endl;
    }
    fibonacci(true);
    cout << "Values reset ... back to first fibonacci number" << endl;

    i = -1;
    while( (++i) != 10){
        cout << fibonacci() << endl;
    }
    fibonacci(true);
    cout << "Values reset ... back to first fibonacci number" << endl;

    return 1;
}
