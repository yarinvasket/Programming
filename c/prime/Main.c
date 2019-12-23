#include <stdio.h>
#include "LinkedList.h"

int main() {
    int primes = 10000;

    LinkedList * primeNumbers = init(3);
    LinkedList * tail = primeNumbers;

    for (int i = 5;; i+=2) {
        start:
        if (i >= primes)
            break;
        LinkedList * curr = primeNumbers;
        while (curr) {
            if (i % curr->data == 0) {
                i += 2;
                goto start;
            }
            curr=curr->next;
        }
        tail = add(tail, i);
    }

    LinkedList * curr = primeNumbers;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
    freeLinkedList(primeNumbers);
    return 0;
}