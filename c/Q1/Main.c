#include <stdio.h>

int main() {
	unsigned int a;
	unsigned int b;
	scanf("%d", &a);
	scanf("%d", &b);
	for (int i = a; i <= b; i++) {
		int aa = i % 10 + i % 100;
		if (aa % 2 != 0 && aa % 7 == 0 && aa % 17 == 0)
			printf("Hello please give me 100 %d\n", i);
	}
	return 0;
}
