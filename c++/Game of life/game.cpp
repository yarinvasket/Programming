#include "game.hpp"
#include "point.hpp"
#include <array>
#include <vector>
#include <string>

template<unsigned int height, unsigned int width>
Game<height, width>::Game(const Point * initialPoints, size_t length) {
	for (Point p : initialPoints) {
		cells[p.y][p.x] = true;
		aliveCells.push_back(p);
	}
}