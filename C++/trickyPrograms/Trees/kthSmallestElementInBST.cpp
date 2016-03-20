#include <iostream>
#include "TreeNode.h"
using std::cout; using std::endl;

Node *kthSmallestElementUtil(Node *node, int smallestElement, int &elementNum){
    if(!node){
        return NULL;
    }

    Node *n = kthSmallestElementUtil(node->left, smallestElement, elementNum);
    if(elementNum == smallestElement){
        return node;
    }
    elementNum++;
    n = kthSmallestElementUtil(node->right, smallestElement, elementNum);
    return n;
}

int kthSmallestElement(Node *node, int smallestElement){
    if(!node){
        return -1;
    }
    int elementNum = 1;
    Node *ansNode = kthSmallestElementUtil(node, smallestElement, elementNum);
    if(!ansNode){
        return -1;
    }
    return (ansNode->data);
}

int main(){
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    int smallestElement = 6;

    cout << "6th smallest element: " << kthSmallestElement(root, smallestElement) << endl;

    return 0;
}
