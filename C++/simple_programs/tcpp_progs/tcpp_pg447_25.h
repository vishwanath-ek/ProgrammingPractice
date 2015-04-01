#ifndef TCPP_PG447_25_H
#define TCPP_PG447_25_H
 
#include <iostream>
#include <string>

class SomeClass {
    std::string someString;

    public:
        SomeClass(std::string arg = ""): someString(arg){
            std::cout << "In Constructor SomeClass, initialized someString to " << someString << std::endl;
        }

        void print(){
            std::cout << "Value of someString is " << someString << std::endl;
        }
};

#endif
