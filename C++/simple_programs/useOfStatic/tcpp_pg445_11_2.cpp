#include <iostream>
#include "tcpp_pg445_11.h"

extern int someInt;
extern SimpleClass simple;

void testFunc(){
    std::cout << "Extern someInt testFunc ..." << someInt << std::endl;
    simple.print();
}
