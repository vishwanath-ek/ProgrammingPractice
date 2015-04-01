#include "tcpp_pg447_25.h"

int main(){
    SomeClass *sc = new SomeClass();
    sc->print();
    delete sc;

    sc = new SomeClass("Vishwa");
    sc->print();
    delete sc;

    return 1;

}
