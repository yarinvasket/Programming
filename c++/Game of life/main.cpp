#include "game.hpp"
#include "point.hpp"
#define HEIGHT 5
#define WIDTH 5

int main() {
	const Point arr[] = {{1, 2}, {2, 3}};
	Game<HEIGHT, WIDTH> game(arr, (size_t)2);
	return 0;
}