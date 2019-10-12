#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	unsigned int base, exponent;
	unsigned long long result = 1;

	printf("Base: ");
	scanf("%d", &base);
	printf("Exponent: ");
	scanf("%d", &exponent);

	for (int i = 0; i < exponent; i++)
		result *= base;
	printf("The result is: %lld\n", result);
}
