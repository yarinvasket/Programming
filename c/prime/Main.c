#include <stdio.h>
#include "LinkedList.h"

int main() {

    LinkedList * primeNumbers = init(3);
    LinkedList * tail = primeNumbers;
    printf("%d\n%d\n", 2, 3);

    for (int i = 5;; i+=2) {
        start: if(1);
        LinkedList * curr = primeNumbers;
        while (curr) {
            if (i % curr->data == 0) {
                i += 2;
                goto start;
            }
            curr=curr->next;
        }
        printf("%d\n", i);
        tail = add(tail, i);
    }
    freeLinkedList(primeNumbers);
    return 0;
}