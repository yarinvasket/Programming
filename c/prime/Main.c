#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList * head = init(3);
    add(head, 65);
    LinkedList * tail = head->next;
    add(tail, 55);
    tail = tail->next;
    add(tail, 35);
    tail = tail->next;
    add(tail, 69);
    tail = tail->next;

    LinkedList * curr = head;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    freeLinkedList(head);
    return 0;
}