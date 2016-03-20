#include <iostream>
#include "TreeNode.h"
using std::cout; using std::endl;

Node *findLCA(Node *node, int data1, int data2){
    if(!node){
        return NULL;
    }

    if( (node->data == data1) || (node->data == data2) ){
        return node;
    }

    Node *left = findLCA(node->left, data1, data2);
    Node *right = findLCA(node->right, data1, data2);

    if(left && right){
        return node;
    }

    return (left ? left: right);
}

int main(){
    /*        5
     *    3   |   8
     *  1   4 | 6    9
     */
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    Node *node = findLCA(root, 4, 6);
    cout << "LCA: " << node->data << endl;

    return 0;
}
