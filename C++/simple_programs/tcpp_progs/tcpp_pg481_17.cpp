#include <iostream>

class DoublePtrClass{
    double *doublePtr;

    public:
        DoublePtrClass(double arg): doublePtr(NULL){
            std::cout << "In Constructor with double arg ..." << std::endl;
            doublePtr = new double;
            *doublePtr = arg;
        }

        DoublePtrClass(const DoublePtrClass& obj, double x = 3){
            doublePtr = new double;
            *doublePtr = *(obj.doublePtr);
            std::cout << "X in args, setting double to : " << x << std::endl;
            *doublePtr = x;
        }

        ~DoublePtrClass(){
            std::cout << "Double: " << *doublePtr << std::endl;
            *doublePtr = -1;
            delete doublePtr;
            doublePtr = 0;
        }
};

void func1(DoublePtrClass doublePtrObj){
    std::cout << "In func1 ..." << std::endl;
    (void)doublePtrObj;
}

int main(){
    DoublePtrClass doublePtrObj1(3.23);
    std::cout << "Calling func1" << std::endl;
    func1(doublePtrObj1);

    return 1;
}
