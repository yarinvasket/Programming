char *memchr(unsigned int n, char *p) {
	int counter = 0;
	for (; *(counter + p); counter++) {}
	return p - n + counter;
}
