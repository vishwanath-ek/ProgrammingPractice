#include <iostream>
#include "tcpp_pg445_16.h"


int main(){
    {
        using namespace ownNS;
        ownNsObj.print();
        func1();
        cout << "In main ... call func2: " << func2() << endl;
        OwnNsClass obj;
        obj.print();
    }

    func3();

    return 1;
}
