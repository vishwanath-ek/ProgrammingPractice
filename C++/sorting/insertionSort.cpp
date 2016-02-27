#include "sortClass.h"

using std::cout; using std::endl;
using std::cerr;

void SortClass::insertionSort(){
    size_t i;
    for( i = 0; i < sz; i++ ){
        int j = i;
        int tempi = i;
        while( j > 0 ){
            j--;
            if ( arr[j] > arr[tempi] ){
                swap(tempi,j);
                tempi--;
            } else {
                break;
            }
        }
    }
}
