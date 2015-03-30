#ifndef TCPP_PG445_16_H
#define TCPP_PG445_16_H

namespace ownNS {
    using std::cout;
    using std::endl;

    void func1(){
        cout << "This is func1, inside ownNS" << endl;
    }

    int func2(){
        cout << "This is func2, inside ownNS, returning 1" << endl;
        return 1;
    }

    class OwnNsClass {
        public:
            OwnNsClass(){
                cout << "OwnNsClass constructor" << endl;
            }

           ~OwnNsClass(){
                cout << "OwnNsClass destructor" << endl;
            }

            void print(){
                cout << "In print inside OwnNsClass" << endl;
            }
    };

    OwnNsClass ownNsObj;
}

namespace {
    using std::cout;
    using std::endl;

    void func3(){
        cout << "In func3 unnamed namespace." << endl;
    }
}

#endif
