#include <iostream>
#include <cstdlib>

using std::cout; using std::endl;
class SomeClass{
    static const int array1[];
    static int array2[];

    public:
        SomeClass(){
            std::cout << "In Constructor ... " << std::endl;
        }

        ~SomeClass(){
            std::cout << "In Destructor ... " << std::endl;
        }

        static void printStaticIntArrays(){
            cout << "static const int Array1:" << endl;
            for(unsigned i = 0; i < 6; i++){
                cout <<  array1[i] << endl;
            }
            cout << "static int Array2:" << endl;
            for(unsigned i = 0; i < 4; i++){
                cout <<  array2[i] << endl;
            }
        }
};

int SomeClass::array2[] = {-1,-2,-3,-4};
const int SomeClass::array1[] = {1,2,3,4,5,6};

int main(){
    SomeClass::printStaticIntArrays();

    return 1;
}
