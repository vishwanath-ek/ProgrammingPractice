#include "sortClass.h"
/* Selection Sort: Traverse array -> getMinIndex -> Swap
 * OuterIndex for Swap and InnerIndex to find minIndex.
 */
void SortClass::selectionSortIterative(){
    for(int i = 0; i < sz - 1; i++){
        int min = i;
        for(int j = i + 1; j < sz; j++){
            if( arr[j] < arr[min] ){
                min = j;
            }
        }
        swap(min, i);
    }
}

int SortClass::findMinIndex(int startPos){
    int min = startPos;
    for(int j = startPos; j < sz; j++){
        if( arr[j] < arr[min]){
            min = j;
        }
    }
    return min;
}

void SortClass::selectionSortRecursive(int startPos){
    if(startPos == sz){
        return; 
    }
    int minPos = findMinIndex(startPos);
    int temp = arr[startPos];
    arr[startPos] = arr[minPos];
    arr[minPos] = temp;
    selectionSortRecursive(startPos + 1);
}
