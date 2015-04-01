#ifndef TCPP_PG446_22_1_H
#define TCPP_PG446_22_1_H
namespace SomeNS1 {
    class SomeClass {
        public:
            SomeClass(){
                std::cout << "In constructor, header 1" << std::endl;
            }

            void print(){
                std::cout << "In print, header 1" << std::endl;
            }

            ~SomeClass(){
                std::cout << "In destructor, header 1" << std::endl;
            }
    };

    SomeClass someclass1;
}
#endif
