#ifndef SORTCLASS_H
#define SORTCLASS_H

#include <iostream>
using std::cout; using std::endl;

class SortClass{
    public:
        SortClass(int* arrPtr, size_t size): arr(NULL), sz(size){
            arr = arrPtr;
        }

        ~SortClass(){
            delete []arr;
            arr = NULL;
        }

        void print(){
            for(size_t x = 0; x < sz; x++){
                cout << arr[x] << " ";
            }
            cout << endl;
        }

        void sort(const std::string& = "selection");

    private:
        int *arr;
        size_t sz;
        size_t findMinIndex(size_t startPos);
        void selectionSortIterative();
        void selectionSortRecursive(size_t startPos);
};

#endif
