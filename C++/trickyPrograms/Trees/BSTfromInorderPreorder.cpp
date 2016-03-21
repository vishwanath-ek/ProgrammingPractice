#include <iostream>
#include <vector>
#include "TreeNode.h"
using std::endl; using std::cout;

size_t findInorderIndex(const char *inorderArr, char toFind,
                        size_t minIndex, size_t maxIndex){
    size_t i = 0;
    for(i = minIndex; i <= maxIndex; i++){
        if (inorderArr[i] == toFind){
            break;
        }
    }
    return i;
}

Node *constructBST(const char *inorderArr, const char *preorderArr, size_t size,
                    size_t &preorderIndex, int minInorderIndex, int maxInorderIndex){
    if (minInorderIndex > maxInorderIndex){
        return NULL;
    }

    Node *node = new Node(preorderArr[preorderIndex]);
    size_t inorderIndex = findInorderIndex(inorderArr, preorderArr[preorderIndex],
                                    minInorderIndex, maxInorderIndex);
    ++preorderIndex;

    node->left = constructBST(inorderArr, preorderArr, size,
                            preorderIndex, minInorderIndex, inorderIndex - 1);
    node->right = constructBST(inorderArr, preorderArr, size,
                            preorderIndex, inorderIndex + 1, maxInorderIndex);

    return node;
}

void inorderTraversal(Node *node){
    if (!node){
        return;
    }
    inorderTraversal(node->left);
    cout << static_cast<char>(node->data) << " ";
    inorderTraversal(node->right);
    return;
}

int main(){
    char inorderArr[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char preorderArr[] = {'A', 'B', 'D', 'E', 'C', 'F'};

    size_t preorderInd = 0;
    Node *root = constructBST(inorderArr, preorderArr, 6, preorderInd, 0, 5);
    inorderTraversal(root);    
    cout << endl;

    return 0;
}
