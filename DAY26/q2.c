
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;   // dummy head
    int size;     // current size of linked list
} MyLinkedList;

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = (Node*)malloc(sizeof(Node)); // dummy node
    obj->head->next = NULL;
    obj->size = 0;
    return obj;
}

/** Get the value of the index-th node in the linked list. If invalid, return -1 */
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head->next;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->val;
}

/** Add at head */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = obj->head->next;
    obj->head->next = newNode;
    obj->size++;
}

/** Add at tail */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    Node* curr = obj->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = newNode;
    obj->size++;
}

/** Add at index */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
    obj->size++;
}

/** Delete at index */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    obj->size--;
}

/** Free memory */
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr != NULL) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}
