#include "sortClass.h"
#include <cstring>

void SortClass::merge(size_t start1, size_t end1,
        size_t start2, size_t end2){
    int *tempArr = new int[end2 - start1 + 1];
    memset(tempArr, 0, sizeof(int)*(end2 - start1 + 1));

    size_t i = start1;
    size_t j = start2;
    size_t index = 0;
    while( i <= end1 && j <= end2 ){
        if( arr[i] < arr[j] ){
            tempArr[index] = arr[i];
            i++;
        } else {
            tempArr[index] = arr[j];
            j++;
        }
        index++;
    }
    if( j > end2 ){
        while( i <= end1 ){
            tempArr[index] = arr[i];
            i++;
            index++;
        }
    }
    if( i > end1 ){
        while( j <= end2){
            tempArr[index] = arr[j];
            j++;
            index++;
        }
    }

    size_t index_arr = start1;
    size_t indexTemp = 0;
    for(; index_arr <= end2 && indexTemp < index; index_arr++, indexTemp++ ){
        arr[index_arr] = tempArr[indexTemp];
    }
    delete []tempArr;
}

void SortClass::mergeSort(size_t startPos, size_t endPos){
    if ( startPos < endPos ){
        size_t middle = (startPos + endPos) / 2;
        mergeSort(startPos, middle);
        mergeSort(middle + 1, endPos);
        merge(startPos, middle, middle + 1, endPos);
    }
    return;
}
