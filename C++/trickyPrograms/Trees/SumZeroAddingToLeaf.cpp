#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;

void sumToZeroUtil(Node *node, int sum, bool &isSumZero, std::vector<int> &path){
    if(!node){
        return;
    }

    sum = sum + node->data;
    if(!node->left && !node->right){
        if(sum == 0){
            isSumZero = true;
            path.push_back(node->data);
        }
        return;
    }

    bool leftSumZero = false;
    bool rightSumZero = false;
    sumToZeroUtil(node->left, sum, leftSumZero, path);
    sumToZeroUtil(node->right, sum, rightSumZero, path);

    if(leftSumZero || rightSumZero){
        isSumZero = true;
        path.push_back(node->data);
    }

    return;
}

std::vector<int> sumToZero(Node *node){
    if(!node){
        return std::vector<int>();
    }

    bool isSumZero = false;
    // Use a stack if you dont want to reverse
    std::vector<int> path;
    sumToZeroUtil(node, 0, isSumZero, path);
    return path;
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

    std::vector<int> path = sumToZero(root);
    if (path.size()){
        std::reverse(path.begin(), path.end());        
        cout << "Thre is a sum to zero till leaf: " << std::boolalpha << true << endl;
        std::vector<int>::const_iterator it = path.begin();
        for(; it != path.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}
