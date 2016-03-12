#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *partitionList(Node *node, int partition){
    Node *lesser = NULL;
    Node *lastLesser = NULL;
    Node *greater = NULL;
    Node *lastGreater = NULL;

    Node *current = node;
    while( current ) {
        if( current->data < partition ){
            Node *tempLesser = (Node *)calloc(1, sizeof(Node));
            tempLesser->data = current->data;
            if(lesser){
                lastLesser->next = tempLesser;
                lastLesser = tempLesser;
            } else {
                lesser = tempLesser;
                lastLesser = lesser;
            }
        } else if( current->data > partition ){
            Node *tempGreater = (Node *)calloc(1, sizeof(Node));
            tempGreater->data = current->data;
            if(greater){
                lastGreater->next = tempGreater;
                lastGreater = tempGreater;
            } else {
                greater = tempGreater;
                lastGreater = greater;
            }
        }
        current = current->next;
    }

    lastLesser->next = (Node *)calloc(1, sizeof(Node));
    lastLesser->next->data = partition;
    lastLesser->next->next = greater;
    return lesser;
}

int main(){
    Node *head = (Node *)calloc(1, sizeof(Node));
    head->data = 2;
    head->next = (Node *)calloc(1, sizeof(Node));
    head->next->data = 3;
    head->next->next = (Node *)calloc(1, sizeof(Node));
    head->next->next->data = 4;
    head->next->next->next = (Node *)calloc(1, sizeof(Node));
    head->next->next->next->data = 1;
    head->next->next->next->next = (Node *)calloc(1, sizeof(Node));
    head->next->next->next->next->data = 5;
    head->next->next->next->next->next = 0;

    printList(head);
    head = partitionList(head, 4);
    printList(head);

    return 0;
}
