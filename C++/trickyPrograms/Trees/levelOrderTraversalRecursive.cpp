#include <iostream>
#include "TreeNode.h"
using std::cout; using std::endl;

void levelOrderTraversePrint(Node *node, size_t level){
    if(!node){
        return;
    }

    if (level == 1){
        cout << node->data << " ";
    } else {
        levelOrderTraversePrint(node->left, level - 1);
        levelOrderTraversePrint(node->right, level - 1);
    }
    return;
}

void levelOrderTraversal(Node *node, size_t level){
    if(!node){
        return;
    }
    
    for(size_t i = 1; i <= level; i++){
        levelOrderTraversePrint(node, i);
        cout << endl;
    }
}

int main(){
    /*        5
     *    -3  |   8
     *  -4  -2| 6    9
     */
    Node *root = new Node(5);
    root->left = new Node(-3);
    root->right = new Node(8);
    root->left->left = new Node(-4);
    root->left->right = new Node(-2);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    size_t level = 2;
    levelOrderTraversal(root, level);

    return 0;
}
