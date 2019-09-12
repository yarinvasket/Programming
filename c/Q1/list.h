#include <stdlib.h>
#include <string.h>

typedef struct st_item {
	char data;
	struct st_item *next;
} Item;

Item *buildList(int *n, char *c) {
	char *arr = (char *) malloc(sizeof(char) * 200);
	gets(arr);
	arr = (char *) realloc(arr, sizeof(char) * strlen(arr));
	char *arrp = arr;
	Item *list = (Item *) malloc(sizeof(Item));
	Item *curr = list;
	unsigned int counter = 0;
	char largest = '\0';
	char currc = *arrp;
	for (; currc != '!'; counter++) {
		currc = *arrp;
		if (currc > largest)
			largest = currc;
		curr->data = currc;
		curr->next = (Item *) malloc(sizeof(Item));
		curr = curr->next;
		arrp++;
	}
	*n = counter;
	*c = largest;
	return list;
}

void printElements(Item *pl) {
	Item *curr = pl;
	while (curr) {
		printf("%c", curr->data);
		curr = curr->next;
	}
	printf("\n");
}
