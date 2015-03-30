#include <iostream>

using std::cout;
using std::endl;

class SomeClass;
void friendFunc(int, SomeClass&);

class SomeClass {
    int someInt;

    public:
        SomeClass(): someInt(0){
            cout << "In Constructor" << endl;
        }

        void print(){
            cout << "This is inside print, someInt " << someInt << endl;
        }

        void setSomeInt(int arg){
            someInt = arg;
        }

        friend void friendFunc(int, SomeClass&);
};

void friendFunc(int arg, SomeClass& someClassObj){
    someClassObj.someInt = arg;
    cout << "Inside friend function, set someInt to " << arg << endl;
}

int main(){
    SomeClass someClassObj;
    someClassObj.print();
    friendFunc(2, someClassObj);
    someClassObj.print();

    return 1;
}
