#include <iostream>
#include "node.h"

using std::cout; using std::endl;
using std::cerr;

template<typename T>
class BinarySearchTree {
    public:
        BinarySearchTree(): root(NULL){
        }

        ~BinarySearchTree(){
            if( !root ){
                delete root;
            }
        }

        void add(T obj);
        T del(T obj);
        bool checkExists(T obj);
        void inOrderTraversal();
        void postOrderTraversal();

    private:
        void inOrderTraverse(Node<T> *node);
        void postOrderTraverse(Node<T> *node);
        Node<T> *insert(Node<T> *node,T obj, const bool &createNode = true, bool& exists = false);
        Node<T> *root;
};

template<typename T>
void BinarySearchTree<T>::inOrderTraverse(Node<T> *node){
    if( !node ){
        return;
    }
    inOrderTraverse(node->getLeft());
    cout << node->getData() << " ";
    inOrderTraverse(node->getRight()); 
}

template<typename T>
void BinarySearchTree<T>::inOrderTraversal(){
    if( !root ){
        cout << "Root is null ..." << endl;
        return;
    }
    inOrderTraverse(root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::postOrderTraverse(Node<T> *node){
    if( !node ){
        return;
    }
    postOrderTraverse(node->getLeft());
    postOrderTraverse(node->getRight()); 
    cout << node->getData() << " ";
}

template<typename T>
void BinarySearchTree<T>::postOrderTraversal(){
    if( !root ){
        cout << "Root is null ..." << endl;
        return;
    }
    postOrderTraverse(root);
    cout << endl;
}

template<typename T>
Node<T> *BinarySearchTree<T>::insert(Node<T> *node, T obj, const bool &createNode, bool& exists){
    if( !createNode && !node ){
        exists = false;
        return node;
    }

    if( !node ){
        return new Node<T>(obj);
    }

    if( node->getData() == obj ){
        exists = true;
    } else if ( node->getData() < obj ){
        Node<T> *insertedNode = insert(node->getRight(), obj, createNode, exists);
        node->setRight(insertedNode); 
    } else {
        Node<T> *insertedNode = insert(node->getLeft(), obj, createNode, exists);
        node->setLeft(insertedNode);
    }

    return node;
}

template<typename T>
void BinarySearchTree<T>::add(T obj){
    if(!root){
        root = new Node<T>(obj);
    }

    bool exists = false;
    (void)insert(root, obj, true, exists);
}

template<typename T>
T BinarySearchTree<T>::del(T obj){
}

template<typename T>
bool BinarySearchTree<T>::checkExists(T obj){
    if( root->getData() == obj ){
        return true;
    }
    bool exists = false;    
    (void)insert(root, obj, false, exists);
    return exists;
}

int main(){
    BinarySearchTree<std::string> binTree;
    std::string allLetters = "ABCDEFGHIJKL";
    std::string emptyString;
    std::string::const_iterator it = allLetters.begin();
    for(; it != allLetters.end(); it++){
        binTree.add(*it + emptyString);
    }

    cout << "--- In Order traversal ---" << endl;
    binTree.inOrderTraversal();
    cout << "--- Post Order Traversal ---" << endl;
    binTree.postOrderTraversal();

    cout << "Existance of E: " << std::boolalpha << binTree.checkExists("E") << endl;
    cout << "Existance of Z: " << std::boolalpha << binTree.checkExists("Z") << endl;
   
     
    return 0;
}
