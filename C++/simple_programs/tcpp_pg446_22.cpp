#include <iostream>
#include "tcpp_pg446_22_1.h"
#include "tcpp_pg446_22_2.h"

int main(){
    SomeNS1::SomeClass sc1;
    sc1.print();

    SomeNS2::SomeClass sc2;
    sc2.print();

    std::cout << "Someclass object header 1:" << std::endl;
    SomeNS1::someclass1.print();

    std::cout << "Someclass object header 2:" << std::endl;
    SomeNS2::someclass2.print();
}
