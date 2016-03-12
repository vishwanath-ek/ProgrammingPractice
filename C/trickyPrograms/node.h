#ifndef NODE_H
#define NODE_H
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} Node;


void printList(Node *head) {
    Node *current = head;
    while (current) {
        fprintf(stdout, "%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

#endif
