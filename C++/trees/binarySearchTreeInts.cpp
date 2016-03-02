#include <iostream>
#include "intNode.h"

using std::cout; using std::endl;
using std::cerr;

class BinarySearchTree {
    public:
        BinarySearchTree(): root(NULL){
        }
        ~BinarySearchTree(){
            if( root ){
                delete root;
            }
        }

        void insert(int key);
        void inorderTraversal();
        bool checkExists(int key);
        int getSuccessor();
        int getPredecessor();
    private:
        Node *insert(Node *node, int key);
        void inorderTraverse(Node *node);
        Node *root;
};

int BinarySearchTree::getSuccessor(){
    if( !root ) {
        cerr << "Root is empty." << endl;
        return INT_MIN;
    }

    Node *tempNode = root->getRight();
    if( !tempNode ) {
        return root->getData();
    }

    while( tempNode->getLeft() ){
        tempNode = tempNode->getLeft();
    }

    return tempNode->getData();
}

int BinarySearchTree::getPredecessor(){
    if( !root ) {
        cerr << "Root is empty." << endl;
        return INT_MIN;
    }

    Node *tempNode = root->getLeft();
    if( !tempNode ) {
        return root->getData();
    }

    while( tempNode->getRight() ){
        tempNode = tempNode->getRight();
    }

    return tempNode->getData();
}

void BinarySearchTree::inorderTraverse(Node *node){
    if( !node ){
        return;
    }
    inorderTraverse(node->getLeft());
    cout << node->getData() << " ";
    inorderTraverse(node->getRight());
}

void BinarySearchTree::inorderTraversal(){
    if( !root ){
        cerr << "Root is empty." << endl;
        return;
    }

    inorderTraverse(root);
    cout << endl;
}

bool BinarySearchTree::checkExists(int key){
    if(!root){
        return false;
    }

    Node *tempNode = root;
    while ( tempNode ){
        if ( tempNode->getData() < key ){
            tempNode = tempNode->getRight();
        } else if ( tempNode->getData() > key ){
            tempNode = tempNode->getLeft();
        } else {
            return true;
        }
    }

    return false;
}

Node *BinarySearchTree::insert(Node *node, int key){
    if ( !node ){
        return new Node(key);
    }

    if( key > node->getData() ){
        Node *right = insert(node->getRight(), key);
        node->setRight(right);
    } else if ( key < node->getData() ){
        Node *left = insert(node->getLeft(), key);
        node->setLeft(left);
    }

    return node;
}

void BinarySearchTree::insert(int key){
    if( !root ){
        root = new Node(key);
        return;
    }

    if(checkExists(key)){
        cerr << "Node already exists, couldn't insert." << endl;
        return;
    }

    if( key > root->getData() ){
        Node *right = insert(root->getRight(), key);
        root->setRight(right);
    } else if ( key < root->getData() ){
        Node *left = insert(root->getLeft(), key);
        root->setLeft(left);
    }
}

int main(){
    BinarySearchTree binTree;
   // binTree.insert(3);
   // bool exists = binTree.checkExists(3);
   // cout << "3 checkExists is: " << std::boolalpha << exists << endl;

    binTree.insert(4); binTree.insert(2); binTree.insert(7); binTree.insert(1);
    binTree.insert(3); binTree.insert(5); binTree.insert(8); binTree.insert(6); 

    cout << "--- Inorder Traversal ---" << endl;
    binTree.inorderTraversal();

    cout << "Predecessor: " << binTree.getPredecessor() << endl;
    cout << "Successor: " << binTree.getSuccessor() << endl;

    return 0;
}
