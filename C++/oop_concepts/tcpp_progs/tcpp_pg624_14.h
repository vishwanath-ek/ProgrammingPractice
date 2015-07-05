#ifndef TCPP_PG624_14_H
#define TCPP_PG624_14_H

#include <iostream>
#include <string>

class Traveler {
    std::string name;

    public:
        Traveler(std::string name){
            std::cout << "In traveler constructor ... 1 arg ..." << std::endl;
            this->name = name;
        }

        Traveler(const Traveler& t){
            std::cout << "In traveler copy constructor ..." << std::endl;
            name = t.name;
        }

        Traveler& operator= (const Traveler& t){
            std::cout << "In traveler assignment operator ..." << std::endl;
            name = t.name;
            return *this;
        }
};

class Pager {
    std::string name;

    public:
        Pager(std::string name){
            std::cout << "In pager constructor ... 1 arg ..." << std::endl;
            this->name = name;
        }

        Pager(const Pager& p){
            std::cout << "In pager copy constructor ..." << std::endl;
            name = p.name;
        }

        Pager& operator= (const Pager& p){
            std::cout << "In pager assignment operator ..." << std::endl;
            name = p.name;
            return *this;
        }
};

class BusinessTraveler : public Traveler {
    Pager p;

    public:
        BusinessTraveler(): Traveler("Vishwanath"), p("default Pager"){
            std::cout << "In default constructor BusinessTraveler ... no arg" << std::endl;    
        }

        BusinessTraveler(std::string name): Traveler(name), p(name + "pager"){
            std::cout << "In constructor BusinessTraveler ... 1 arg" << std::endl;
        }

        BusinessTraveler(const BusinessTraveler& bt): Traveler(bt), p(bt.p){
            std::cout << "In BusinessTraveler copy constructor ..." << std::endl;
        }

        BusinessTraveler& operator= (const BusinessTraveler& bt){
            Traveler::operator=(bt);
            p = bt.p;
            std::cout << "In BusinessTraveler assignment operator ..." << std::endl;

            return *this;
        }
};

#endif
