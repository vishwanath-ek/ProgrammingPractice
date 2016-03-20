#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using std::cout; using std::endl;

class Node {
    public:
        Node(int x): data(x), left(NULL), right(NULL) {}
        ~Node(){
            if(left){
                cout << "Deleting Left: " << std::hex << left << " ";
                delete left;
            }
            left = NULL;
            if(right){
                cout << "Deleting Right: " << std::hex << right << " ";
                delete right;
            }
            right = NULL;
        }
        int data;
        Node *left;
        Node *right;
};

void printTree(Node *node) {
    if(!node){
        return;
    }

    printTree(node->left);
    cout << node->data << endl;
    printTree(node->right);
}

#endif
