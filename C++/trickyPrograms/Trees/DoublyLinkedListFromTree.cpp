#include <iostream>
#include "TreeNode.h"
using std::cout; using std::endl;

void createDoublyLinkedList(Node *node, Node **head, Node **tail){
    if (!node){
        return;
    }

    static Node *prev = NULL;
    createDoublyLinkedList(node->left, head, tail);
    if(!*head){
        *head = node;
    }
    if(prev){
        node->left = prev;
        prev->right = node;
    }
    prev = node;
    *tail = node;
    createDoublyLinkedList(node->right, head, tail);

    return;
}

void printList(Node *node){
    Node *tempNode = node;
    while(tempNode){
        cout << tempNode->data << " ";
        tempNode = tempNode->right;
    }
    cout << endl;

    return;
}

void deleteLinkedList(Node *node) {
    if(!node){
        return;
    }

    deleteLinkedList(node->right);
    node->left = NULL;
    node->right = NULL;
    delete node;
    return;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);

    Node *head = NULL;
    Node *tail = NULL;
    createDoublyLinkedList(root, &head, &tail);
    tail->right = NULL;

    printList(head);

    deleteLinkedList(head);
}
