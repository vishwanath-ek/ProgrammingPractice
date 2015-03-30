#include <iostream>

using std::cout; using std::endl;

class IntArrayClass {
    static const int arr_size = 10;
    int int_arr[arr_size];
    static int someint;
    const int var;

    public:
        IntArrayClass(int intPassed): var(intPassed) {
            cout << "In Constructor: const int " << var << ", static int " << someint << endl;
            for(int i = 0; i < arr_size; i++){
                int_arr[i] = i;
            }
        }

        static void printStaticVariable();

        void printArr() {
            cout << "Array ->" << endl;
            for(int i = 0; i < arr_size; i++){
                cout << int_arr[i] << endl;
            }
            cout << "---- END OF ARRAY ----" << endl;
        }

        ~IntArrayClass(){
            cout << "In Destructor" << endl;
        }
};

int IntArrayClass::someint = 1;

void IntArrayClass::printStaticVariable() {
    cout << "Static varible - static int " << IntArrayClass::someint << endl;
}


int main(){
    IntArrayClass intArrObj(12);
    IntArrayClass::printStaticVariable();
    intArrObj.printArr();

    return 1;
}
