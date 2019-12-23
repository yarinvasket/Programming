#include <stdio.h>
#include "LinkedList.h"

int main() {
    LinkedList * head = init(3);
    LinkedList * tail = add(head, 65);
    tail = add(tail, 55);
    tail = add(tail, 35);
    tail = add(tail, 69);

    LinkedList * curr = head;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    freeLinkedList(head);
    return 0;
}