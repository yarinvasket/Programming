#include <stdlib.h>

typedef struct LinkedList {
	char data;
	struct LinkedList *next;
} LinkedList;

void addChar(LinkedList **last, char c) {
	*last = (LinkedList *) malloc(sizeof(char));
	(*last)->data = c;
	printf("%c\n", (*last)->data); //debug
}

void deleteList(LinkedList *pl) {
	LinkedList *pcurr = pl;
	while (pcurr) {
		free(&(pcurr->data));
		pcurr = pcurr->next;
	}
}

void printElements(LinkedList *pl) {
	LinkedList *pcurr = pl;
	while (pcurr) {
		printf("%c\n", pcurr->data);
		pcurr = pcurr->next;
	}
}
