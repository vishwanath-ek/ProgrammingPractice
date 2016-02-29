#ifndef SORTCLASS_H
#define SORTCLASS_H

#include <iostream>
using std::cout; using std::endl;

class SortClass{
    public:
        SortClass(int* arrPtr, int size): arr(NULL), sz(size){
            arr = arrPtr;
        }

        ~SortClass(){
            delete []arr;
            arr = NULL;
        }

        void print(){
            for(int x = 0; x < sz; x++){
                cout << arr[x] << " ";
            }
            cout << endl;
        }

        void sort(const std::string& = "selection", int pos = 0);

    private:
        int *arr;
        int sz;
        void swap(int, int);
        int findMinIndex(int startPos);
        void selectionSortIterative();
        void selectionSortRecursive(int startPos);
        void insertionSort();
        void merge(int, int, int, int);
        void mergeSort(int startPos, int endPos);
        int partition(int pivotPos, int startPos, int endPos);
        void quickSort(int startPos, int endPos);
        void quickSelect(int pos, int startPos, int endPos);

};

#endif
