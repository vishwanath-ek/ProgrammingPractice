#include <stdio.h>
#include <stdlib.h>
#include "node.h"

void kthToLast(Node *node, int *count) {
    if(!node){
        return;
    }

    kthToLast(node->next, count);
    if( *count == 1 ){
        printf("%d\n", node->data);
        --*count;
        return;
    }

    --*count;
    return;
}

int main() {
    Node *head = (Node *)calloc(1, sizeof(Node));
    head->data = 2;
    head->next = (Node *)calloc(1, sizeof(Node));
    head->next->data = 3;
    head->next->next = (Node *)calloc(1, sizeof(Node));
    head->next->next->data = 4;
    head->next->next->next = (Node *)calloc(1, sizeof(Node));
    head->next->next->next->data = 1;
    head->next->next->next->next = 0;
    
    printList(head);
    fprintf(stdout, "3rd Element to the last: ");

    int i = 3;
    kthToLast(head, &i);

    return 0;
}
