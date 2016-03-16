#include <iostream>
#include <cstdlib>
#include "TreeNode.h"
using std::cout; using std::endl;

int checkHeight(Node *node) {
    if(!node){
        return 0;
    }

    int leftHeight = checkHeight(node->left);
    if( leftHeight == -1 ){
        return -1;
    }

    int rightHeight = checkHeight(node->right);
    if( rightHeight == -1 ){
        return -1;
    }

    int diffHeight = abs(leftHeight - rightHeight);
    if( diffHeight > 1){
        return -1;
    }
    return (std::max(leftHeight, rightHeight) + 1);
}

bool checkBalanced(Node *node) {
    if(!node){
        return true;
    }
    int height = checkHeight(node);
    if(height == -1){
        return false;
    }
    return true;
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(8);
    root->left->left->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left = new Node(7);

    printTree(root);
    cout << std::boolalpha << checkBalanced(root) << endl;
    return 0;
}
