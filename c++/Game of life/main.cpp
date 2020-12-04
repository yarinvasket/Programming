#include "game.hpp"
#include "consts.hpp"
#include <iostream>
#include <chrono>

int main() {
	auto startTime = std::chrono::high_resolution_clock::now();
	const Point arr[] = ARR;
	Game game(arr, SIZE);

	for (unsigned int i = 0; i < MOVES; i++) {
		game.doTurn();
	}
	auto endTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
	std::cout << "Process done in " << duration << "ms.\n";
	return 0;
}