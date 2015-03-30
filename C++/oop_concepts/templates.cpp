#include <iostream>
#include <string>

template<class T, class U>
U add(T a, U b){
    return a + b;
}

// Person Class
template<class T = std::string>
class Person {
    protected:
        std::string name;
        int age;
    public:
        Person();
        ~Person();
        T add(T, T);
};

template<class T>
Person<T>::Person(){
    name = "vishwa";
    age = 25;
}

template<class T>
Person<T>::~Person(){
}

template<class T>
T Person<T>::add(T a, T b){
    return a + b;
}
//~: End Person class
int
main(){
    std::cout << add<int, double>(1,2.5) << std::endl;
    std::cout << add(std::string("A"), std::string("B")) << std::endl;

    Person<int> p;
    std::cout << p.add(2,3) << std::endl;

    Person<> pstr;
    std::cout << pstr.add(std::string("A"), std::string("B")) << std::endl;

    return 0;
}

