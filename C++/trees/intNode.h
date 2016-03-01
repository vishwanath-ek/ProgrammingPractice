#ifndef INTNODE_H
#define INTNODE_H
#include <climits>
class Node {
    public:
        Node(): data(INT_MIN), left(NULL), right(NULL){
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
            return data;
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
        int data;
        Node *left;
        Node *right;
};
#endif
