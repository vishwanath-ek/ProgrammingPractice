#include <iostream>
using std::cout;
using std::endl;

class Node {
    public:
        Node(int x): data(x), next(NULL){}
        ~Node(){
            if( next ){
                delete next;
            }
            cout << "In desctructor of " << data << endl; 
        }
        int data;
        Node *next;
};

Node *reverseLinkedList(Node *head){
    Node *current = head;
    Node *previous = NULL;
    Node *ahead = NULL;

    while(current){
        ahead = current->next;
        current->next = previous;
        previous = current;
        current = ahead;
    }
    return previous;
}

void printList(Node *head){
    Node *current = head;
    while(current){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    printList(head);
    head = reverseLinkedList(head);
    printList(head);
    delete head;

    return 0;
}
