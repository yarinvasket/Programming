#include "stuff.hpp"
#include <math.h>

double f(double x) {
	return 1 / (1 + exp(-x));
}

double g(double x) {
	return -log((1 - x) / x);
}