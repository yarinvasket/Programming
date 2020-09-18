#pragma once
#include "point.hpp"
#include "consts.hpp"
#include <array>
#include <vector>
#include <string>

class Game {
	private:
		std::array<std::array<bool, WIDTH>, HEIGHT> cells;
		std::vector<Point> aliveCells;
	
	public:
		Game(const Point * initialPoints, size_t length);
		void doTurn();
		std::string getBoard();
};