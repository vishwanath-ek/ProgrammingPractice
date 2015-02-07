#ifndef MULTIPLEINHERITANCE_H
#define MULTIPLEINHERITANCE_H
class Person {
    public:
        int age;
        std::string name;
        Person();
        virtual void whoAreYou();
        virtual ~Person();
};

class UndergradStudent: virtual public Person {
    public:
        UndergradStudent();
        void whoAreYou();
        ~UndergradStudent();
};

class GradStudent: virtual public Person {
    public:
        GradStudent();
        void whoAreYou();
        ~GradStudent();
};

class Doctor: public UndergradStudent, public GradStudent {
    public:
        Doctor();
        void whoAreYou();
        ~Doctor();
};
#endif
