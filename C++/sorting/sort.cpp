#include <iostream>
#include <cstdlib>
#include "sortClass.h"
using std::cout; using std::endl;
using std::cerr;

void SortClass::sort(const std::string &type){
    cout << "You chose " << type <<" sort ..." << endl;
    if ( type == "selection" ){
        // SortClass::selectionSortIterative();
        SortClass::selectionSortRecursive(0);
    } else if ( type == "insertion" ){
        SortClass::insertionSort();
    } else if ( type == "merge" ){
        SortClass::mergeSort(0, sz - 1);
    }
}

void SortClass::swap(size_t i, size_t j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    return;
}

int main(){
    int *arr = new int[10];
    for(int i = 0; i <= 9; i++){
        arr[i] = 9-i;
    }

    SortClass desc(arr, 10);
    cout << "--- BEFORE SORT ---" << endl;
    desc.print();
    cout << "--- AFTER SORT ---" << endl;
    desc.sort("merge");
    desc.print();

    return 0;
}
