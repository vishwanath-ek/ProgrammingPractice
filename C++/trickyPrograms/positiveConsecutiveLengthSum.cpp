#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> maxSet(std::vector<int> &A) {
    long long maxSum = 0;
    long long sum = 0;
    int end = 0;
    int totalSumElements = 0;
    int maxTotalSumElements = 0;
    for(size_t i = 0; i < A.size(); i++){
        if( A[i] >= 0 ){
            totalSumElements++;
            sum += A[i];
            if( maxSum < sum ){
                end = i;
                maxSum = sum;
            } else if( maxSum == sum ){
                if(totalSumElements > maxTotalSumElements){
                    maxTotalSumElements = totalSumElements;
                    end = i;
                }
            }
        } else {
            totalSumElements = 0;
            sum = 0;
        }
    }

    std::vector<int> B;
    for(int i = end; A[i]>=0 && i >= 0; i--){
        B.push_back(A[i]);
    }
    std::reverse(B.begin(), B.end());
    return B;
}

int main(){
    using std::cout; using std::endl;
    int arr[] = {0 , 0 , -1 , 0};
    int numElements = sizeof(arr)/sizeof(int);

    std::vector<int> vect;
    for(int i = 0; i < numElements; i++){
        vect.push_back(arr[i]);
    }

    std::vector<int> A = maxSet(vect);
    for(size_t i = 0; i < A.size(); i++){
        cout << A[i] << endl;
    }

    return 0;
}
