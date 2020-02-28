#include <iostream>
#include "LinkedList.hpp"
using namespace std;

int main()
{
    cout << "2\n3\n";
    
    LinkedList * primeNumbers = new LinkedList(3);
    for (int i = 5;; i += 2)
    {
        Node * curr = primeNumbers->head;
        while (1)
        {
            if (!curr->next)
            {
                if (i % curr->data != 0)
                {
                    primeNumbers->add(i);
                    cout << i << "\n";
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
    return 0;
}