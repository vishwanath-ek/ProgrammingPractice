#include "sortClass.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
int SortClass::partition(int pivotPos, int startPos, int endPos){
    int i = startPos;
    int j = endPos;
    
    if(startPos >= endPos){
        return startPos;
    }

    while( i <= endPos && j >= startPos && i <= j ){
        if( arr[i] <= arr[pivotPos] ){
            i++;
        }
        if( arr[j] >= arr[pivotPos] ){
            j--;
        }
        if( i < j && arr[i] > arr[pivotPos] && arr[j] < arr[pivotPos] ){
            swap(i, j);
            i++;
            j--;
        }
    }
    swap(j, pivotPos);
    return j;
}

void SortClass::quickSelect(int pos, int startPos, int endPos){
    if(startPos <= endPos){
        int pivotPos = startPos;
        pivotPos = partition(pivotPos, startPos, endPos);
        if( (pos - 1) == pivotPos){
            cout << pos << "th smallest element: " << arr[pivotPos] << endl;
            return;
        }
        if( (pos - 1) >  pivotPos ){
            startPos = pivotPos + 1;
            quickSelect(pos, startPos, endPos);
        } else {
            endPos = pivotPos - 1;
            quickSelect(pos, startPos, endPos);
        }
    }
}

void SortClass::quickSort(int startPos, int endPos){
    if(startPos < endPos){
        int pivotPos = startPos;
        pivotPos = partition(pivotPos, startPos, endPos);
        quickSort(startPos, pivotPos - 1);
        quickSort(pivotPos + 1, endPos);
    }
}
