#include <iostream>
#include "tcpp_pg444_456.h"

using std::cout;
using std::endl;

int Monitor1::num_incidents_call = 0;

Monitor1 *global_func(){
    static Monitor1 monitor;
    return &monitor;
}

void call_monitor2( Monitor1 *mon1 ) {
    static Monitor2 monitor2(mon1);
}

Monitor2 mon2(global_func());

int main(){
    //global_func();
    //global_func();
    //global_func();

//    call_monitor2(global_func());

    return 1;
}
