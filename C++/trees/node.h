#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
    public:
        Node(): left(NULL), right(NULL){
        }

        Node(T obj): data(obj), left(NULL), right(NULL){
        }

        ~Node(){
            if( !left ){
                delete left;
            }
            if( !right ){
                delete right;
            }
        }

        T getData(){
            return data;
        }

        Node<T> *getLeft(){
            return left;
        }

        Node<T> *getRight(){
            return right;
        }

        void setRight(Node<T> *node){
            right = node;
        }

        void setLeft(Node<T> *node){
            left = node;
        }

    private:
        T data;
        Node<T> *left;
        Node<T> *right;
};

#endif
