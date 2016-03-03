#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>
#include <assert.h>

Node *head = NULL;

Node *getLastNode(){
    Node *tempNode = head;
    while( tempNode->next != NULL ){
        tempNode = tempNode->next;
    }
    return tempNode;
}

void insertIntoLinkedList(int data){
    if(!head) {
        head = (Node *)malloc(sizeof(Node));
        head->data = data;
        head->next = NULL;
        return;
    }

    Node *tempNode = getLastNode();
    tempNode->next = (Node *)malloc(sizeof(Node));
    tempNode->next->data = data;
    tempNode->next->next = NULL;
}

void printList(Node *node){
    Node *tempNode = node;

    while( tempNode ) {
        printf("%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    puts("");
}


int hasLoop(){
    Node *nodeBehind = head;
    Node *nodeAhead = head->next;
    while (nodeAhead && nodeBehind){
        if(nodeAhead == nodeBehind){
            return 1;
        }
        if (nodeAhead->next && nodeAhead->next->next){
            nodeAhead = nodeAhead->next->next;
        } else {
            break;
        }
        if(nodeBehind->next){
            nodeBehind = nodeBehind->next;
        } else {
            break;
        }
    }
    return 0;
}

void reverseList(Node *head, Node **newHead){
    assert(head != NULL);

    Node *behindNode = head;
    Node *middleNode = head->next;
    Node *aheadNode = head->next->next;

    if( !middleNode ){
        *newHead = head;
        return;
    }
    if( !aheadNode ){
        middleNode->next = head;
        behindNode->next = NULL;
    }

    short start = 1;
    while(aheadNode){
        middleNode->next = behindNode;
        if( start ){
            behindNode->next = NULL;
            start = 0;
        }
        behindNode = middleNode;
        middleNode = aheadNode;
        aheadNode = aheadNode->next;
    }
    middleNode->next = behindNode;

    *newHead = middleNode;
    (void)newHead;

    return;
}

void freeList(Node *node){
    assert(node != NULL);

    Node *aheadNode = node->next;
    if( !aheadNode ){
        free(node);
        return;
    }

    while( aheadNode ){
        free(node);
        node = aheadNode;
        aheadNode = aheadNode->next;
    }

    free(node);
}

int main(){
    insertIntoLinkedList(1);
    insertIntoLinkedList(2);
    insertIntoLinkedList(3);
    insertIntoLinkedList(4);
    insertIntoLinkedList(5);

    printList(head);

/*
    Node *tempNode = head;
    while (tempNode->next){
        tempNode = tempNode->next;
    }
    tempNode->next = head->next->next;
*/
    hasLoop() ? puts("Has a loop"): puts("No loop");

    Node *newHead = NULL;
    reverseList(head, &newHead);
    printList(newHead);

    freeList(head);
    freeList(newHead);

    exit(EXIT_SUCCESS);
}
