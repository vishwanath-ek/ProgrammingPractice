#include <iostream>

class SomeClass{
    int i;
    public:
        SomeClass(): i(0){
        }

        void printConst() const {
            std::cout << "Inside const func i: " << i << std::endl;
        }

        void changeNonConst(int i){
            this->i = i;
            std::cout << "Changed from non-const function, current i: " << i << std::endl;
        }
};

void func1( SomeClass someClass ){
    using namespace std;
    cout << "---- func1 ----" << endl;
    someClass.printConst();
    someClass.changeNonConst(3);
    cout << endl;
}

void func2( SomeClass& someClass ){
    using namespace std;
    cout << "---- func2 ----" << endl;
    someClass.printConst();
    someClass.changeNonConst(5);
    cout << endl;
}

void func3( const SomeClass& someClass ){
    using namespace std;
    cout << "---- func3 ----" << endl;
    someClass.printConst();
    //someClass.changeNonConst(7); Compiler Error.
    cout << endl;
}

int main(){
    SomeClass someClass;
    func1(someClass);
    func2(someClass);
    func3(someClass);

    const SomeClass obj;
    //obj.changeNonConst(3); Compiler Error.
    func1(obj);
    //func2(obj); Compiler Error.
    func3(obj);

    return 1;
}
