#include <iostream>
#include "tcpp_pg445_16.h"

using namespace ownNS;

int main(){
    ownNsObj.print();
    func1();
    cout << "In main ... call func2: " << func2() << endl;
    OwnNsClass obj;
    obj.print();

    return 1;
}
