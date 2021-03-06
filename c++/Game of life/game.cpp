#include "game.hpp"
#include "consts.hpp"
#include "pair_hash.hpp"
#include <array>
#include <unordered_set>
#include <string>
#include <unordered_map>

Game::Game(const Point * initialPoints, size_t length) {
	for (unsigned int i = 0; i < HEIGHT; i++) {
		for (unsigned int j = 0; j < WIDTH; j++) {
			cells[i][j] = false;
		}
	}

	for (size_t i = 0; i < length; i++) {
		auto p = initialPoints[i];
		cells[std::get<1>(p)][std::get<0>(p)] = true;
		aliveCells.insert(p);
	}
}

std::string Game::getBoard() {
	std::string ret = "";
	for (unsigned int i = 0; i < HEIGHT; i++) {
		for (unsigned int j = 0; j < WIDTH; j++) {
			ret += cells[i][j] ? (unsigned char)219 : ' ';
		}
		ret += '\n';
	}
	return ret;
}

void Game::doTurn() {
	//map containing the number of neighbors of every cell
	std::unordered_map<Point, unsigned short, pair_hash> neighbors;
	
	//give every cell its number of neighbors
	for (auto p : aliveCells) {
		neighbors.insert({p, 0});
		auto x = std::get<0>(p);
		auto y = std::get<1>(p);
		auto destX = x < WIDTH - 1 ? x + 1 : WIDTH - 1;
		auto destY = y < HEIGHT - 1 ? y + 1 : HEIGHT - 1;

		for (unsigned int srcY = y > 0 ? y - 1 : 0; srcY <= destY; srcY++) {
			for (unsigned int srcX = x > 0 ? x - 1 : 0; srcX <= destX; srcX++) {
				if (srcX == x && srcY == y) continue;
				neighbors[{srcX, srcY}]++;
			}
		}
	}

	//take an action on every cell accordingly
	for (auto v : neighbors) {
		auto p = std::get<0>(v);
		auto y = std::get<1>(p);
		auto x = std::get<0>(p);
		auto neighborCount = std::get<1>(v);

		if (cells[y][x]) {
			if (neighborCount < 2 || neighborCount > 3) {
				cells[y][x] = false;
				aliveCells.erase(p);
			}
		}
		else if (neighborCount == 3) {
			cells[y][x] = true;
			aliveCells.insert(p);
		}
	}
}