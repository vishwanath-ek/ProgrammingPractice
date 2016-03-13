#include <iostream>
#include <stack>

using std::cout; using std::endl;

std::stack<int> sort(std::stack<int> &unsortedStack){
    std::stack<int> sortedStack;
    while(!unsortedStack.empty()){
        int unsortedTop = unsortedStack.top();
        unsortedStack.pop();
        if(sortedStack.empty()){
            sortedStack.push(unsortedTop);
        } else {
            while(!sortedStack.empty() && sortedStack.top() > unsortedTop){
                int sortedTop = sortedStack.top();
                sortedStack.pop();
                unsortedStack.push(sortedTop);
            }
            sortedStack.push(unsortedTop);
        }
    }
    return sortedStack;
}

void printStack(std::stack<int> sortedStack){
    while(!sortedStack.empty()){
        cout << sortedStack.top() << endl;
        sortedStack.pop();
    }
    return;
}

int main(){
    std::stack<int> unsortedStack;
    unsortedStack.push(1);
    unsortedStack.push(3);
    unsortedStack.push(1);
    unsortedStack.push(2);
    unsortedStack.push(4);
    unsortedStack.push(5);


    std::stack<int> sortedStack = sort(unsortedStack);
    printStack(sortedStack);

    return 0;
}
