#include <iostream>
#include <vector>
#include <algorithm>

using std::cout; using std::endl;

void printVector(std::vector<int> A){
    for(size_t i = 0; i < A.size(); i++){
        cout << A[i] << endl;
    }
    return;
}

int main(){
    std::vector<int> A;
    A.push_back(2);
    A.push_back(1);
    A.push_back(3);
    cout << "--- Original Vector ---" << endl;
    printVector(A);

    std::sort(A.begin(), A.end());
    cout << "--- Sorted vector, normal sort ---" << endl;
    printVector(A);

    std::sort(A.begin(), A.end(), std::greater<int>());
    cout << "--- Sorted vector, greater sort ---" << endl;
    printVector(A);
    return 0;
}
