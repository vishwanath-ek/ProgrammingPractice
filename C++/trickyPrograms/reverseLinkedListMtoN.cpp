#include <iostream>

using std::cout; using std::endl;

class ListNode {
    public:
        ListNode(int x): val(x), next(NULL) {} 
        int val;
        ListNode *next;
};

ListNode* reverseBetween(ListNode* A, int m, int n) {
    ListNode *tempNodePrev = A;
    int i = 1;
    while(i < (m - 1)){
        tempNodePrev = tempNodePrev->next;
        i++;
    }
    ListNode *first = tempNodePrev;
    while(i < n){
        tempNodePrev = tempNodePrev->next;
        i++;
    }
    // f p m la
    // 1 2 3 4  5 6 7 //
    //   m n        
    ListNode *last = tempNodePrev;
    ListNode *prev = first->next;
    ListNode *middle = prev->next;
    ListNode *ahead = middle->next;
    while( middle != last ){
        middle->next = prev;
        prev = middle;
        middle = ahead;
        if (ahead){
            ahead = ahead->next;
        }
    }

    ListNode *firstNext = first->next;
    first->next = prev;
    firstNext->next = last;

    return A;
}

void printList(ListNode *A){
    ListNode *tempNode = A;
    while(tempNode){
        cout << tempNode->val << " ";
        tempNode = tempNode->next;
    }
    cout << endl;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);


    printList(head);
    cout << "--- After Reverse ---" << endl;
    reverseBetween(head, 2, 8);
    printList(head);

    return 0;
}
