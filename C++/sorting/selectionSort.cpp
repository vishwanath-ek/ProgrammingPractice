#include "sortClass.h"
/* Selection Sort: Traverse array -> getMinIndex -> Swap
 * OuterIndex for Swap and InnerIndex to find minIndex.
 */
void SortClass::selectionSortIterative(){
    for(size_t i = 0; i < sz - 1; i++){
        int min = i;
        for(size_t j = i + 1; j < sz; j++){
            if( arr[j] < arr[min] ){
                min = j;
            }
        }
        swap(min, i);
    }
}

size_t SortClass::findMinIndex(size_t startPos){
    size_t min = startPos;
    for(size_t j = startPos; j < sz; j++){
        if( arr[j] < arr[min]){
            min = j;
        }
    }
    return min;
}

void SortClass::selectionSortRecursive(size_t startPos){
    if(startPos == sz){
        return; 
    }
    size_t minPos = findMinIndex(startPos);
    int temp = arr[startPos];
    arr[startPos] = arr[minPos];
    arr[minPos] = temp;
    selectionSortRecursive(startPos + 1);
}
