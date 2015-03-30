#include <iostream>
#include <string>
#include "multiple_inheritance.h"

// Person Class definitions
Person::Person(){
    std::cout << "In constructor parent" << std::endl;
}

Person::~Person(){
        std::cout << "In destructor parent" << std::endl;
}

void
Person::whoAreYou(){
    std::cout << "I am a person" << std::endl ;
}
//:~ Person class definitions end

// Student class definitions
UndergradStudent::UndergradStudent(){
    std::cout << "In constructor undergrad child" << std::endl;
}

UndergradStudent::~UndergradStudent(){
    std::cout << "In destructor undergrad child" << std::endl;
}

void
UndergradStudent::whoAreYou(){
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

// Doctor definitions
Doctor::Doctor(){
    std::cout << "In constructor doctor" << std::endl;
}

void
Doctor::whoAreYou(){
    std::cout << "Im a doctor" << std::endl;
}

Doctor::~Doctor(){
    std::cout << "In destructor doctor" << std::endl;
}
//:~ Doctor definitions end

int
main(){
    Doctor *d1 = new Doctor();
    d1->whoAreYou();
    d1->name = "vishwa";
    d1->age = 24;
    delete d1;
}
