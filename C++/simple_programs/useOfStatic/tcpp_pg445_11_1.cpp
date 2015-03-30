#include <iostream>
#include "tcpp_pg445_11.h"

using std::cout;
using std::endl;

int someInteger = 10;
SimpleClass *simple = NULL; 

int main(){
    simple = new SimpleClass(someInteger);
    simple->print();
    delete simple;
}
