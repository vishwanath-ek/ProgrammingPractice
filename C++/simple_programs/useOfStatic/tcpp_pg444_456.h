#ifndef TCPP_PG444_456_H
#define TCPP_PG444_456_H

class Monitor1 {
    static int num_incidents_call;

    public:
        Monitor1(){
            std::cout << "In Constructor mon1 ..." << std::endl;
            incident();
            print();
        }

        ~Monitor1(){
            std::cout << "In Destructor mon1 ... "  << std::endl;
            decrement();
            print();
        }

        static void incident(){
            ++num_incidents_call;
        }

        static void decrement(){
            --num_incidents_call;
        }

        static void print(){
            std::cout << "Inside print - Number of incidents: " << num_incidents_call << std::endl;
        }
};

class Monitor2 {
    Monitor1 *mon1;

    public:
        Monitor2(Monitor1 *mon1_obj): mon1(NULL){
            std::cout << "In Constructor mon2 ..." << std::endl;
            mon1 = mon1_obj;
            mon1->incident();
            mon1->print();
        }

        ~Monitor2(){
            std::cout << "In Destructor mon2 ..." << std::endl;
            mon1->decrement();
            mon1->print();
        }
};

#endif
