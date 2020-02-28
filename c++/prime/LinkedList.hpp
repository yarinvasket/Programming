#include "Node.hpp"

class LinkedList {
    private:
        Node * head;
        Node * tail;

    public:
        LinkedList(int data)
        {
            head = new Node(data);
            tail = head;
        }
};