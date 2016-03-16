#include <iostream>
#include <climits>
#include "TreeNode.h"

using std::cout;
using std::endl;

bool checkBinarySearchTree(Node *node, int min, int max){
    if( !node ){
        return true;
    }
    if( node->data < min || node->data > max ){
        return false;
    }
    return checkBinarySearchTree(node->left, min, node->data) && 
        checkBinarySearchTree(node->right, node->data, max);
}

bool checkBinaryTree(Node *node){
    if( !node ){
        return true;
    }

    return checkBinarySearchTree(node, INT_MIN, INT_MAX);
}

int main(){
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->left->left = new Node(0);
    root->right->right = new Node(7);
    root->right->left = new Node(5);

    cout << std::boolalpha << checkBinaryTree(root) << endl;

    return 0;
}
