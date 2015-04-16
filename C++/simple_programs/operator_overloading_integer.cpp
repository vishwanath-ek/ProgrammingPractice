#include <iostream>

// Overload Operators:
//      - + & ++ -- ! ~

class Integer {
    int i;

    Integer* This(){
        return this;
    }

    public:
        Integer(int ii = 0): i(ii) {}
        
        Integer(const Integer& intarg): i(intarg.i){
            std::cout << "In Copy Const." << std::endl;
        }

        void print() const {
            std::cout << "i: " << i << std::endl;
        }

        friend const Integer& operator+(const Integer&);
        friend Integer operator-(const Integer&);
        friend const Integer* operator&(Integer&);
        
        // Prefix ++
        friend Integer& operator++(Integer&);
        // Postfix ++
        friend Integer operator++(Integer&, int);
        
        // Similar to ++
        friend Integer& operator--(Integer&);
        friend Integer operator--(Integer&, int);

        // += -=
        friend Integer operator+=(Integer& integer, int);
        friend Integer operator-=(Integer& integer, int);
};

const Integer& operator+(const Integer& integer){
    std::cout << "Operator +" << std::endl;
    return integer;
}

Integer operator-(const Integer& integer){
    std::cout << "Operator -" << std::endl;
    Integer intcopy(-integer.i);
    return intcopy;
}

const Integer* operator&(Integer& integer){
    std::cout << "Operator &" << std::endl;
    return integer.This();
}

Integer& operator++(Integer& integer){
    std::cout << "Operator ++ prefix" << std::endl;
    integer.i = integer.i + 1;
    return integer;
}

Integer operator++(Integer& integer, int){
    std::cout << "Operator ++ postfix" << std::endl;
    Integer intcopy = integer;
    (integer.i)++;
    return intcopy;
}

int main(){
    Integer int1(23);
    +int1;
    
    int1 = -int1;
    int1.print();

    const Integer* int2 = &int1;
    (*int2).print();

    std::cout << "--- Prefix add ---"<< std::endl;
    (++int1).print();
    int1.print();

    std::cout << "--- Postfix add ---"<< std::endl;
    (int1++).print();
    int1.print();

    return 1;
}
