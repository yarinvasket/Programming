#pragma once
#include "point.hpp"
#include <array>
#include <vector>
#include <string>

template<unsigned int height, unsigned int width>
class Game {
	private:
		std::array<std::array<bool, width>, height> cells;
		std::vector<Point> aliveCells;
	
	public:
		Game(const Point * initialPoints, size_t length);

		void doTurn();
		std::string getBoard();
};