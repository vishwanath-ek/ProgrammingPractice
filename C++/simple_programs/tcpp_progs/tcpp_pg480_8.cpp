#include <iostream>

char& modChar(char& a){
    ++a;
    return a;
}

int main(){
    using std::cout; using std::endl;

    char a[]={'a','b','c','d'};
    unsigned int len = sizeof(a)/sizeof(a[0]);

    cout << "Return from function ..."<< endl;
    for(unsigned int i = 0; i < len; i++){
        cout << modChar(a[i]) << ", ";
    }
    cout << endl;

    cout << "Original array ..."<< endl;
    for(unsigned int i = 0; i < len; i++){
        cout << a[i] << ", ";
    }
    cout << endl;

    return 1;
}
