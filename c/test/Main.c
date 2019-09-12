#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *str = (char *) malloc(200 * sizeof(char));
	gets(str);
	printf("%d\n", strlen(str));
	str = (char *) realloc(str, sizeof(char) * strlen(str));
	for (char *curr = str; 1; curr++) {
		if (*curr == '!')
			break;
		printf("%c", *curr);
	}
	free(str);
	printf("\n");
}
