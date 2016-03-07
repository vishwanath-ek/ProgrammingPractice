#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using std::cout; using std::endl;

int main(){
    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
    for( int i = 0; i < 5; i++){
        pq.push(i);
    }

    cout << "Top: " << pq.top() << endl;

    while(!pq.empty()){
        int i = pq.top();
        cout << i << endl;
        pq.pop();
    }

    return 0;
}
