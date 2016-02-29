#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::cerr;

template<typename T>
class MinHeap {
    public:
        MinHeap(): heapVector(){
        }

        void add(T obj){
            if ( heapVector.size() == 0 ){
                heapVector.push_back(obj);
            }
            heapVector.push_back(obj);
            bubbleUp();
        }

        T getSmallest() { return heapVector[1]; }
        T removeSmallest();
        void print();
        size_t getSize() { return heapVector.size(); }
    private:
        void swap(int i, int j) {
            T obj = heapVector[i];
            heapVector[i] = heapVector[j];
            heapVector[j] = obj;
        }
        void bubbleUp();
        void bubbleDown();
        std::vector<T> heapVector;
};

template<typename T>
T MinHeap<T>::removeSmallest(){
    T smallest = heapVector[1];
    heapVector[1] = heapVector.back();
    heapVector.pop_back();
    bubbleDown();
    return smallest;
}

template<typename T>
void MinHeap<T>::bubbleUp(){
    size_t startPos = heapVector.size() - 1;
    size_t endPos = 1;
    while ( startPos != endPos ){
        if ( heapVector[startPos] < heapVector[startPos/2] ){
            swap(startPos, startPos/2);
            startPos = startPos/2;
        } else {
            break;
        }
    }
}

template<typename T>
void MinHeap<T>::bubbleDown() {
    size_t startPos = 1;
    size_t endPos = heapVector.size() - 1;
    while (startPos <= endPos){
        int minPos = startPos;
        if ( (startPos*2 < heapVector.size()) && 
                heapVector[startPos] > heapVector[startPos * 2]){
            minPos = startPos*2;
        }
        if ( ((startPos*2 + 1) < heapVector.size()) &&
                heapVector[startPos] > heapVector[startPos * 2 + 1]){
            if( heapVector[startPos * 2 + 1] < heapVector[minPos] ){
                minPos = startPos * 2 + 1;
            }
        }

        if (minPos == startPos){
            break;
        }
        swap(minPos, startPos);

        if ( minPos == startPos*2 ){
            startPos = startPos*2;
        }
        if( minPos == (startPos*2 + 1) ){
            startPos = startPos*2 + 1;
        }
    }
}

template<typename T>
void MinHeap<T>::print(){
    typename std::vector<T>::const_iterator it = heapVector.begin() + 1;
    for(; it != heapVector.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    MinHeap<std::string> heap;
    std::string tempString = "ABCDEFGHIJKL";
    std::string emptyString;
    for (std::string::iterator it = tempString.end() - 1; it >= tempString.begin(); it--){
        std::string s = *it + emptyString;
        heap.add(s);
    }

    heap.print();

    std::string removedString = heap.getSmallest();
    cout << "Get Smallest: " << removedString << endl;

//    removedString = heap.removeSmallest();
//    cout << "Removed Smallest: " << removedString << endl;

//    heap.print();

    cout << "---- Heap Sort ----" << endl;
    size_t count = 1;
    size_t heapSize = heap.getSize();
    for (; count < heapSize; count++){
        cout << heap.removeSmallest() << " ";
    }
    cout << endl;

    return 0;
}
