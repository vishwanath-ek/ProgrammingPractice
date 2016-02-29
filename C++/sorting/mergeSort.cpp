#include "sortClass.h"
#include <cstring>

void SortClass::merge(int start1, int end1,
        int start2, int end2){
    int *tempArr = new int[end2 - start1 + 1];
    memset(tempArr, 0, sizeof(int)*(end2 - start1 + 1));

    int i = start1;
    int j = start2;
    int index = 0;
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

    int index_arr = start1;
    int indexTemp = 0;
    for(; index_arr <= end2 && indexTemp < index; index_arr++, indexTemp++ ){
        arr[index_arr] = tempArr[indexTemp];
    }
    delete []tempArr;
}

void SortClass::mergeSort(int startPos, int endPos){
    if ( startPos < endPos ){
        int middle = (startPos + endPos) / 2;
        mergeSort(startPos, middle);
        mergeSort(middle + 1, endPos);
        merge(startPos, middle, middle + 1, endPos);
    }
    return;
}
