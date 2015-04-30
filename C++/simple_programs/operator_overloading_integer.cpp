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
        //friend Integer& operator--(Integer&);
        //friend Integer operator--(Integer&, int);

        // += -=
        friend Integer& operator+=(Integer& integer, int);
        
        // Member Functions ...
        Integer& operator-=(int x){
            std::cout << "Operator -= ... Memeber function" << std::endl;
            i -= x;
            return *this;
        }

        //Binary +
        Integer operator+(const Integer& integer){
            std::cout << "Operator +" << std::endl;
            return Integer(i + integer.i);
        }

        // = has to be Memeber function as to overload the default
        // Copy assignment bit-by-bit copy operator.
        Integer& operator=(const Integer& integer){
            std::cout << "Operator =" << std::endl;
            i = integer.i;
            return *this;
        }
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

Integer& operator+=(Integer& integer, int x){
    std::cout << "Operator +=" << std::endl;
    integer.i += x;
    return integer;
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

    std::cout << "--- += Operator ---" << std::endl;
    int1 += 2;
    int1.print();

    std::cout << "--- -= Operator ---" << std::endl;
    int1 -= 2;
    int1.print();

    std::cout << "<---- Cascading ---->" << std::endl;
    Integer int3(5);
    // the + operator is overloaded as 2 is automatically
    // converted to Integer class as constructor is not "explicit"
    Integer int4 = ((int3++) + 2);
    int4 -= 3;
    int4.print();

    std::cout << "----- = Operator -----" << std::endl;
    Integer int5 = int4;
    (int5 = int4) = int3;
    std::cout << "int3: " << std::endl;
    int3.print();
    std::cout << "int4: " << std::endl;
    int4.print();
    std::cout << "int5: " << std::endl;
    int5.print();

    return 1;
}
