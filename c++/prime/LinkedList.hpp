#include "Node.hpp"

class LinkedList {
    public:
        Node * head;
        Node * tail;

        LinkedList(int data)
        {
            head = new Node;
            head->data = data;
            tail = head;
        }

        void add(int data)
        {
            tail->next = new Node;
            tail = tail->next;
            tail->data = data;
        }
};