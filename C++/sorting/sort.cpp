#include <iostream>
#include <cstdlib>
#include "sortClass.h"
using std::cout; using std::endl;
using std::cerr;

void SortClass::sort(const std::string &type){
    cout << "You chose " << type <<" sort ..." << endl;
    if( type == "selection" ){
        // SortClass::selectionSortIterative();
        SortClass::selectionSortRecursive(0);
    }
}

int main(){
    int *arr = new int[5]();
    for(int i = 0; i <= 4; i++){
        arr[i] = 4-i;
    }

    SortClass desc(arr, 5);
    cout << "--- BEFORE SORT ---" << endl;
    desc.print();
    cout << "--- AFTER SORT ---" << endl;
    desc.sort();
    desc.print();

    return 0;
}
