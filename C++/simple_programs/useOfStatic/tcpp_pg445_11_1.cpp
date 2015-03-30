#include <iostream>
#include "tcpp_pg445_11.h"

using std::cout;
using std::endl;

void testFunc();
int someInt = 10;
SimpleClass simple(someInt);

int main(){
    simple.print();
    testFunc();
}
