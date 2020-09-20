#include "game.hpp"
#include "consts.hpp"
#include <iostream>

int main() {
	const std::tuple<unsigned int, unsigned int> arr[] = ARR;
	Game game(arr, (size_t)2);
	std::cout << game.getBoard();
	return 0;
}