#ifndef INTNODE_H
#define INTNODE_H
#include <climits>
class Node {
    public:
        Node(): key(INT_MIN), left(NULL), right(NULL){
        }
        Node(int k): key(k), left(NULL), right(NULL){
        }
        ~Node(){
            if ( !left ) {
                delete left;
            }
            if ( !right ){
                delete right;
            }
        }

        int getData() {
            return key;
        }

        Node *getLeft(){
            return left;
        }

        Node *getRight(){
            return right;
        }

        void setLeft(Node *node){
            left = node;
        }

        void setRight(Node *node){
            right = node;
        }

    private:
        int key;
        Node *left;
        Node *right;
};
#endif
