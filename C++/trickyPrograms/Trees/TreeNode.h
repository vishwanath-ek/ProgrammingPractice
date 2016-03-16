#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>
using std::cout; using std::endl;

class Node {
    public:
        Node(int x): data(x), left(NULL), right(NULL) {}
        ~Node(){
            if(left){
                delete left;
            }
            if(right){
                delete right;
            }
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
