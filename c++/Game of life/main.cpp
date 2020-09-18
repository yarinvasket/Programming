#include "game.hpp"
#include "point.hpp"
#include "consts.hpp"
#include <iostream>

int main() {
	const Point arr[] = ARR;
	Game game(arr, (size_t)2);
	std::cout << game.getBoard();
	return 0;
}