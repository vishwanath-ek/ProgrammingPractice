#include <iostream>
#include <cstdint>

int*& modArrayLoc(int*& a){
    *a = -1;
    return a;
}

void printArray(int *a, uint8_t count){
    std::cout << "*** size ****" << int(count) << std::endl;
    for(uint8_t i = 0; i < count; i++ ){
        std::cout << a[i] << ", ";
    }
    std::cout << std::endl;
}

int main(){
    using std::cout; using std::endl;

    int a[]={1,2,3,4,5,6};
    cout << "Initial Print array ..." << endl;
    printArray(a, sizeof(a)/sizeof(int));

    int* ptr = &a[4];
    int* arrayPtr = modArrayLoc(ptr);
    cout << "Array location using ptr returned: " << *arrayPtr << endl;
    printArray(a, sizeof(a)/sizeof(int));

    return 1;
}
