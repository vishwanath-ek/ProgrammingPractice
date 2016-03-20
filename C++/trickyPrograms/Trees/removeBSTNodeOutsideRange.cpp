#include <iostream>
#include "TreeNode.h"
using std::cout;
using std::endl;

void printInorderTraverse(Node *node){
    if(!node){
        return;
    }
    printInorderTraverse(node->left);
    cout << node->data << " ";
    printInorderTraverse(node->right);
}

void printInorderTraversal(Node *node){
    if (!node){
        return;
    }
    printInorderTraverse(node);
    cout << endl;
}

Node *removeOutsideRange(Node *node, int min, int max){
    if( !node ){
        return NULL;
    }

    node->left = removeOutsideRange(node->left, min, max);
    node->right = removeOutsideRange(node->right, min, max);

    if (node->data < min){
        Node *right = node->right;
        node->right = NULL;
        node->left = NULL;
        delete node;
        return right;
    }
    if (node->data > max){
        Node *left = node->left;
        node->right = NULL;
        node->left = NULL;
        delete node;
        return left;
    }

    return node;
}

int main() {
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

    printInorderTraversal(root);
    root = removeOutsideRange(root, 3, 6);
    printInorderTraversal(root);

    return 0;
}
