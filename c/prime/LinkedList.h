#include <stdlib.h>

typedef struct LinkedList {
    struct LinkedList * next;
    int data;
} LinkedList;

LinkedList * init(int data) {
    LinkedList * linkedList = (LinkedList *) calloc(1, sizeof(LinkedList));
    linkedList->data = data;
    return linkedList;
}

void add(LinkedList * linkedList, int data) {
    LinkedList * next = (LinkedList *) calloc(1, sizeof(LinkedList));
    linkedList->next = next;
    next->data = data;
}

void freeLinkedList(LinkedList * head) {
    LinkedList * next = head->next;
    free(head);

    if (next) {
        freeLinkedList(next);
    }
}