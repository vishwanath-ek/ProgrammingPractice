#ifndef OOPHEADER_H
#define OOPHEADER_H

class Person {
    protected:
        int age;
        std::string name;
    public:
        Person();
        Person(std::string, int);
        void setNameAge(std::string name, int age);
        std::string getName();
        int getAge();
        virtual void whoAreYou();
        virtual ~Person();
};

class Student: public Person{
    public:
        Student();
        void whoAreYou();
        ~Student();    
};

class GradStudent: public Student{
    public:
        GradStudent();
        void whoAreYou();
        ~GradStudent();
};
#endif
