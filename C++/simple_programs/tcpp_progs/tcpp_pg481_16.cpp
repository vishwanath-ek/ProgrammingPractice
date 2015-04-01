#include <iostream>
// NVRO is named value return optimization which may result in not calling
// the copy constructor. Instead of creating a temporary object, it directly
// assigns to the destination object.
class SomeClass {
    int *someInt;

    public:
        SomeClass(): someInt(NULL) {
            std::cout << "In constructor ..." << std::endl;
        }

        SomeClass( int x ): someInt(NULL) {
            std::cout << "In constructor with int arg..."\
            << std::endl;
            someInt = new int;
            *someInt = x;
        }

        SomeClass(const SomeClass& x): someInt(NULL){
            if( x.someInt ){
                if( !someInt ){
                    someInt = new int;
                }
                *someInt = *(x.someInt);
            }
            std::cout << "In Copy Constructor ..." << std::endl;
        }

        ~SomeClass(){
            if( someInt ){
                delete someInt;
            }
            std::cout << "In destructor ..." << std::endl;
        }

        void print(){
            std::cout << "someInt: " << *someInt << std::endl;
        }
};

void func1(SomeClass someClass){
    std::cout << "In func1, ";
    someClass.print();
}

SomeClass func2(SomeClass someClass){
    std::cout << "In func2, ";
    SomeClass someClassRet = someClass;
    someClassRet.print();
    std::cout << "Returning local object" << std::endl;

    return someClassRet;
}

int main(){
    SomeClass someClass(10);
    SomeClass someClass1 = someClass;

    std::cout << "Calling func1 ---->" << std::endl;
    func1(someClass1);

    std::cout << "Calling func2 ----->" << std::endl;
    SomeClass someClass2 = func2(someClass1);
    someClass2.print();

    return 1;
}
