#include <iostream>
#include <vector>
#include <list>
#include "TreeNode.h"

using std::cout; using std::endl;

void createLinkedListEachLevel(Node *node,
            std::vector<std::list<Node *> > &vectLists, size_t level){
    if(!node){
        return;
    }

    std::list<Node *> listNodes;
    if(vectLists.size() > level){
        listNodes = vectLists.at(level);
    }
    listNodes.push_back(node);

    if(vectLists.size() > level){
        vectLists[level] = listNodes;
    } else {
        vectLists.push_back(listNodes);
    }

    createLinkedListEachLevel(node->left, vectLists, level + 1);
    createLinkedListEachLevel(node->right, vectLists, level + 1);

    return;
}

void createLinkedList(Node *node){
    if(!node){
        return;
    }

    std::vector<std::list<Node *> > vectorLists;
    createLinkedListEachLevel(node, vectorLists, 0);
    for(size_t i = 0; i < vectorLists.size(); i++){
        std::list<Node *> nodesList = vectorLists.at(i);
        std::list<Node *>::const_iterator it = nodesList.begin();
        for(; it != nodesList.end(); it++){
            cout << (*it)->data << " ";
        }
        cout << endl;
    }
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

    createLinkedList(root);

    return 0;
}
