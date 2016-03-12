#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *sumListsWithCarry(Node *node1, Node *node2, int *carry) {
    if(node1 == NULL && node2 == NULL){
        return NULL;
    }

    Node *node = sumListsWithCarry(node1->next, node2->next, carry);

    int result = node1->data + node2->data + *carry;
    if(result >= 10){
        result = result - 10;
        *carry = 1;
    } else {
        *carry = 0;
    }
    Node *addNode = (Node *)calloc(1, sizeof(Node));
    addNode->data = result;
    addNode->next = node;

    return addNode;
}

Node *sumLists(Node *node1, Node *node2) {
    if(node1 == NULL && node2 == NULL){
        return NULL;
    }

    int carry = 0;
    Node *node = sumListsWithCarry(node1, node2, &carry);
    if(carry == 1){
        Node *tempNode = (Node *)calloc(1, sizeof(Node));
        tempNode->data = carry;
        tempNode->next = node;
        node = tempNode;
    }
    return node;
}

int main() {
    Node *head1 = (Node *)calloc(1, sizeof(Node));
    head1->data = 2;
    head1->next = (Node *)calloc(1, sizeof(Node));
    head1->next->data = 3;
    head1->next->next = (Node *)calloc(1, sizeof(Node));
    head1->next->next->data = 4;
    head1->next->next->next = (Node *)calloc(1, sizeof(Node));
    head1->next->next->next->data = 1;
    head1->next->next->next->next = (Node *)calloc(1, sizeof(Node));
    head1->next->next->next->next->data = 5;
    head1->next->next->next->next->next = 0;

    Node *head2 = (Node *)calloc(1, sizeof(Node));
    head2->data = 8;
    head2->next = (Node *)calloc(1, sizeof(Node));
    head2->next->data = 3;
    head2->next->next = (Node *)calloc(1, sizeof(Node));
    head2->next->next->data = 4;
    head2->next->next->next = (Node *)calloc(1, sizeof(Node));
    head2->next->next->next->data = 8;
    head2->next->next->next->next = (Node *)calloc(1, sizeof(Node));
    head2->next->next->next->next->data = 5;
    head2->next->next->next->next->next = 0;

    printList(head1);
    printList(head2);
    printf("-------- Sum --------\n");
    Node *newHead = sumLists(head1, head2);
    printList(newHead);

    return 0;
}
