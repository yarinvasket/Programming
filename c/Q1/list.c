#include <stdio.h>
#include "list.h"

int main() {
	char lar;
	int size;
	Item *l = buildList(&size, &lar);
	printf("%c\n%d\n", lar, size);
	printElements(l);
}
