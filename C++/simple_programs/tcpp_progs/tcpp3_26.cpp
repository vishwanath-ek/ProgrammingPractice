#include <iostream>
#include <cstdio>

void
func(void *ptr, int num_bytes, int value){
    char *char_ptr = static_cast<char *>(ptr);
    for(int i = 0; i < num_bytes; i++){
        char_ptr[i] = value ; 
    }

    return;
}

void
printArray(int *ptr, int size){
    std::cout << "Inside PrintArray : "<< sizeof(ptr)/sizeof(ptr[0]) << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << ptr[i] << " ";
    }
    std::cout << std::endl;
}

int
main(void){
    int arrayInt[]={ 10, 20, 30, 40, 50 };
    void *ptr = static_cast<void *>(arrayInt);
    func(ptr, 7, -1);
    std::cout << "Inside main: " << sizeof(arrayInt)/sizeof(arrayInt[0]) << std::endl;
    printArray(arrayInt, sizeof(arrayInt)/sizeof(arrayInt[0]));
    return 0;
}
