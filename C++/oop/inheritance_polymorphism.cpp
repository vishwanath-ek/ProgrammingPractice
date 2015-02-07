#include <iostream>
#include <string>
#include "oopheader.h"

// Person Class definitions
Person::Person(){
    std::cout << "In constructor parent" << std::endl;
    age = 0;
}

Person::Person(std::string name, int age){
    this->name = name;
    this->age = age;
}

Person::~Person(){
        std::cout << "In destructor parent" << std::endl;
}

void
Person::setNameAge(std::string name, int age){
    this->name = name;
    this->age = age;
}

std::string
Person::getName(){
    return name;
}

int
Person::getAge(){
    return age;
}

void
Person::whoAreYou(){
    std::cout << "I am a person" << std::endl ;
}
//:~ Person class definitions end

// Student class definitions
Student::Student(){
    std::cout << "In constructor child" << std::endl;
}

Student::~Student(){
    std::cout << "In destructor child" << std::endl;
}

void
Student::whoAreYou(){
    std::cout << "Im a student" << std::endl;
}
//:~ Student class definitions end

// Grad Student definitions
GradStudent::GradStudent(){
    std::cout << "In constructor gradstudent" << std::endl;
}

void
GradStudent::whoAreYou(){
    std::cout << "Im a gradstudent" << std::endl;
}

GradStudent::~GradStudent(){
    std::cout << "In destructor gradstudent" << std::endl;
}
//:~ Grad Student definitions end
int
main(){
    // Parent //
    std::cout << "Inheritance:" << std::endl;
    Person *p1 = new Person();
    delete p1;

    // Child //
    Student *s1 = new Student();
    delete s1;

    std::cout << "Polymorphism:" << std::endl;
    p1 = new Student();
    p1->setNameAge("Vishwa",24);
    p1->whoAreYou();
    delete p1;

    p1 = new GradStudent();
    p1->setNameAge("Vishwa",24);
    p1->whoAreYou();
    delete p1;

    p1 = new Person();
    p1->setNameAge("Vishwa",24);
    p1->whoAreYou();
    delete p1;

    return 0;
}
