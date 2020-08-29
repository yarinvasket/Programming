#include "stuff.hpp"
#include <math.h>

double f(double x) {
	return 2 / (2 + exp(-x));
}

double g(double x) {
	return -log((2 - 2 * x) / x);
}