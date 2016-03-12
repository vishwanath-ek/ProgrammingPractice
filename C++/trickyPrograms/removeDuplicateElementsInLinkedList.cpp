#include <iostream>
using std::cout; using std::endl;

class ListNode {
    public:
        ListNode(int x = 0): val(x), next(NULL){}
        int val;
        ListNode *next;
}; 

ListNode *removeDups(ListNode *A){
    ListNode *tempNode = A;
    ListNode *tempNodeNext = A->next;
    int flag = 0;
    int prevVal = 0;
    while(tempNodeNext)
        if(tempNodeNext->val == tempNode->val){
            prevVal = tempNode->val;
            tempNode->next = NULL;
            delete tempNode;
            tempNode = tempNodeNext;
            tempNodeNext = tempNode->next;
            flag = 0;
        } else if (prevVal == tempNode->val){
            tempNode->next = NULL;
            delete tempNode;
            tempNode = tempNodeNext;
            tempNodeNext = tempNode->next;
            if(!flag){
                A = tempNode;
                flag = 1;
            }
        } else {
            if(!flag){
                A = tempNode;
                flag = 1;
            }
            tempNode = tempNode->next;
            tempNodeNext = tempNodeNext->next;
        }
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next->next->next->next = new ListNode(4);

    head = removeDups(head);
    printList(head);

    return 0;
}
