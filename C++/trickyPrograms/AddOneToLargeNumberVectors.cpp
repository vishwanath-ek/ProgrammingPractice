#include <iostream>
#include <vector>
using std::cout; using std::endl;
using std::vector;

vector<int> plusOne(vector<int> &A) {
    int carry = 0;
    int lastDigitAddition = A[A.size() - 1] + 1;
    if(lastDigitAddition >= 10){
        lastDigitAddition = lastDigitAddition - 10;
        carry = 1;
    }
    
    A[A.size() - 1] = lastDigitAddition;
    for(int i  = A.size() - 2; i >= 0; i--){
        A[i] += carry;
        if(A[i] >= 10){
            A[i] = A[i] - 10;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    std::vector<int> B;
    if(carry){
        B.push_back(carry);
    }
    size_t Aind = 0;
    int checkOnce = 0;
    for(; Aind < A.size(); Aind++){
        if( !carry && A[Aind] == 0 && !checkOnce ){
            continue;
        } else {
            checkOnce = 1;
        }
        B.push_back(A.at(Aind));
    }
 
    return B;
}

void printVector(std::vector<int> A){
    for(size_t i = 0; i < A.size(); i++){
        cout << A.at(i) << " ";
    }

    cout << endl;
}

int main(){
    std::vector<int> A;
    A.push_back(0);
    printVector(A);      

    printVector(plusOne(A));

    return 0;
}
