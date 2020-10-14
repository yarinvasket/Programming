#include "game.hpp"
#include "consts.hpp"
#include <iostream>

int main() {
	const Point arr[] = ARR;
	Game game(arr, SIZE);
	std::cout << game.getBoard();

	for (unsigned int i = 0; i < MOVES; i++) {
		game.doTurn();
		std::cout << game.getBoard();
	}
	std::cin.get();
	return 0;
}