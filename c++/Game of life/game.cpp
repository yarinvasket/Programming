#include "game.hpp"
#include "point.hpp"
#include <array>
#include <vector>
#include <string>

Game::Game(const Point * initialPoints, size_t length) {
	for (size_t i = 0; i < length; i++) {
		Point p = initialPoints[i];
		cells[p.y][p.x] = true;
		aliveCells.push_back(p);
	}
}