#include <iostream>
#include "tcpp_pg624_14.h"
using std::cout; using std::endl;

int main(){
    BusinessTraveler bt;
    BusinessTraveler bt1("Sidd");

    BusinessTraveler bt2(bt);
    bt2 = bt1;

    return 0;
}
