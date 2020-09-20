#include "game.hpp"
#include "consts.hpp"
#include <iostream>

int main() {
	const std::pair<unsigned int, unsigned int> arr[] = ARR;
	Game game(arr, (size_t)2);
	std::cout << game.getBoard();
	game.doTurn();
	std::cout << game.getBoard();
	return 0;
}