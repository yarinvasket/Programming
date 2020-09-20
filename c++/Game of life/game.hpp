#pragma once

#include "consts.hpp"
#include "pair_hash.hpp"
#include <array>
#include <unordered_set>
#include <string>

class Game {
	private:
		std::array<std::array<bool, WIDTH>, HEIGHT> cells;
		std::unordered_set<std::pair<unsigned int, unsigned int>, pair_hash> aliveCells;
	
	public:
		Game(const std::pair<unsigned int, unsigned int> * initialPoints, size_t length);
		//performs a turn
		void doTurn();
		//get string representing the game's current board
		std::string getBoard();
};