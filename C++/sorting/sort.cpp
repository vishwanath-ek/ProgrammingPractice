#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortClass.h"
using std::cout; using std::endl;
using std::cerr;

void SortClass::sort(const std::string &type, int pos){
    cout << "You chose " << type <<" ..." << endl;
    if ( type == "selection" ){
        // SortClass::selectionSortIterative();
        SortClass::selectionSortRecursive(0);
    } else if ( type == "insertion" ){
        SortClass::insertionSort();
    } else if ( type == "merge" ){
        SortClass::mergeSort(0, sz - 1);
    } else if ( type == "quick" ){
        SortClass::quickSort(0, sz-1);
    } else if ( type == "quickselect" ){
        SortClass::quickSelect(pos, 0, sz - 1);
    }
}

void SortClass::swap(int i, int j){
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
    return;
}

int main(){
    srand(time(NULL));
    int *arr = new int[10];
    for(int i = 0; i <= 9; i++){
        arr[i] = rand()%100;
    }
//    72 83 72 90 95 56 19 34 97 91 
//    arr[0] = 72; arr[1] = 83; arr[2] = 72; arr[3] = 98 ; arr[4] = 95;
//    arr[5] = 56; arr[6] = 19; arr[7] = 34; arr[8] = 97; arr[9] = 91; 

//    92 25 1 100 2 0
//    arr[0] = 92; arr[1] = 25; arr[2] = 1; arr[3] = 100 ; arr[4] = 2;
//    arr[5] = 0;

    SortClass desc(arr, 10);
    cout << "--- BEFORE SORT ---" << endl;
    desc.print();
    cout << "--- AFTER SORT ---" << endl;
    desc.sort("quick", 4);
    desc.print();

    return 0;
}
