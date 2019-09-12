#include <stdio.h>
#include "LinkedList.h"

int main() {
	LinkedList l;
	LinkedList *last = &l;
	addChar(&last, 'a');
	addChar(&last, 'b');
	addChar(&last, 'c');
	printElements(&l);
	deleteList(&l);
	return 0;
}
