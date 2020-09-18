#include "game.hpp"
#include "point.hpp"
#include <array>
#include <vector>
#include <string>

Game::Game(const Point * initialPoints, size_t length) {
	for (unsigned int i = 0; i < HEIGHT; i++) {
		for (unsigned int j = 0; j < WIDTH; j++) {
			cells[i][j] = false;
		}
	}

	for (size_t i = 0; i < length; i++) {
		Point p = initialPoints[i];
		cells[p.y][p.x] = true;
		aliveCells.push_back(p);
	}
}

std::string Game::getBoard() {
	std::string ret = "";
	for (unsigned int i = 0; i < HEIGHT; i++) {
		for (unsigned int j = 0; j < WIDTH; j++) {
			ret += cells[i][j] ? '*' : ' ';
		}
		ret += '\n';
	}
	return ret;
}