#include <stdio.h>
#include <stdlib.h>

int main() {
	int *ptr = (int *) malloc(sizeof(int));
	printf("%p\n", ptr);
	return 0;
}
