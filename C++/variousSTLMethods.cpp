#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <set>
#include <map>

// Operations to cover:
//  insert back front
//  remove
//  get front back top peek
//  search

using std::cout; using std::endl;

void stackProcess(){
    cout << "---- Stack ----" << endl;
    std::stack<int> intStack;
    if (intStack.empty()){
        cout << "stack is empty." << endl;
    }
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    int j = intStack.top();
    cout << "Top Element: " << j << endl;
    intStack.pop();

    intStack.push(4);
    intStack.push(5);
}

void queueProcess(){
    std::queue<int> q;
    if(q.empty()){
        cout << "Queue is empty." << endl;
    }
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    int i = q.front();
    cout << "Front: " << i << endl;
    i = q.back();
    cout << "Back: " << i << endl;
}

void printDeque(const std::deque<int> &dq){
    std::deque<int>::const_iterator it = dq.begin();
    for(; it != dq.end(); it++){
        cout << *it << endl;
    }
}

void dequeProcess(){
    std::deque<int> dq;
    if( dq.empty() ){
        cout << "deque is empty." << endl;
    }
    for(int i = 0; i< 6; i++ ){
        dq.push_back(i);
    }

    printDeque(dq);
    int i = dq.front();
    cout << endl << "deque front: " << i << endl;
    i = dq.back();
    cout << "deque back:" << i << endl;

    dq.pop_back();
    dq.pop_front();

   // dq.erase(iterator);
    
}

void vectorProcess(){
    std::vector<int> vect;
    
    for(int i = 0; i< 6; i++ ){
        vect.push_back(i);
    }

    cout << "At 2: ";
    cout << vect.at(2) << endl;

    vect.pop_back();
    //vector.erase(iterator);
    cout << "front: " << vect.front() << endl;
    cout << "back: " << vect.back() << endl;
}

void listProcess(){
    std::list<int> dq;
    if( dq.empty() ){
        cout << "deque is empty." << endl;
    }
    for(int i = 0; i< 6; i++ ){
        dq.push_back(i);
    }

    int i = dq.front();
    cout << endl << "deque front: " << i << endl;
    i = dq.back();
    cout << "deque back:" << i << endl;

    dq.pop_back();
    dq.pop_front();

   // dq.erase(iterator);
}

int main(){
    //stackProcess();
    //queueProcess();
    //dequeProcess();
    //vectorProcess();
    listProcess();

    return 0;
}
