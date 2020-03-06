#include "LinkedList.hpp"

LinkedList primeNumbers(3);

void run() {
    for (int i = 5;; i += 2)
    {
        Node * curr = primeNumbers.head;
        for (;;)
        {
            if (!curr->next)
            {
                if (i % curr->data != 0)
                {
                    primeNumbers.add(i);
                }
                break;
            }
            
            if (i % curr->data == 0)
            {
                break;
            }
            curr = curr->next;
        }
    }
}