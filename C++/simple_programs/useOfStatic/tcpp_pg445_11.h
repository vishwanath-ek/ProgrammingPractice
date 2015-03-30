#ifndef TCPP_PG445_11_H
#define TCPP_PG445_11_H

class SimpleClass {
    int someInt;

    public:
        SimpleClass(int arg): someInt(arg){
            std::cout << "In Constructor, set the someInt member." << std::endl;
        }

        ~SimpleClass(){
            std::cout << "In Destructor ..." << std::endl;
        }

        void print(){
            std::cout << "someInt: " << someInt << std::endl;
        }
};

#endif
