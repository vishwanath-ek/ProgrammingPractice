#include <iostream>
#include <stack>
using std::cout; using std::endl;

class Queue {
    public:
        size_t size();
        int front();
        void push(int);
        void pop();
    private:
        std::stack<int> stackNew, stackOld;
        void shiftDataStacks();
};

void Queue::shiftDataStacks(){
    if(stackOld.empty()){
        while(!stackNew.empty()){
            int top = stackNew.top();
            stackNew.pop();
            stackOld.push(top);
        }
    }
    return;
}

size_t Queue::size(){
    return stackNew.size() + stackOld.size();
}

int Queue::front(){
    shiftDataStacks();
    return stackOld.top();
}

void Queue::push(int x){
    stackNew.push(x);
    return;
}

void Queue::pop(){
    shiftDataStacks();
    if(!stackOld.empty()){
        stackOld.pop();
    }
}

int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "--- After pushing 3 elements - 1, 2, 3 ---" << endl;
    cout << "Size: " << q.size() << endl;
    cout << "Front Element: " << q.front() << endl;
    q.pop();
    cout << "Front after pop:" << q.front() << endl;

    return 0;
}
