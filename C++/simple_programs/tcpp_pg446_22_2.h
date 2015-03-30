#ifndef TCPP_PG446_22_2_H
#define TCPP_PG446_22_2_H
namespace SomeNS2 {
    class SomeClass {
        public:
            SomeClass(){
                std::cout << "In constructor, header 2" << std::endl;
            }

            void print(){
                std::cout << "In print, header 2" << std::endl;
            }

            ~SomeClass(){
                std::cout << "In destructor, header 2" << std::endl;
            }
    };

    SomeClass someclass2;
}
#endif
