#include <iostream>
using namespace std;
#define P(EX) void EX() { cout << "function " #EX << endl; }

P(a);
P(b);
P(c);
P(d);

int
main(void){
    a();
    b();
    void (*func_array[])() = {a, b, c, d};
    (func_array[2])();
    (func_array[3])();

    return 0;
}
