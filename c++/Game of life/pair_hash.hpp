#pragma once

#include "consts.hpp"
#include <unordered_set>

struct pair_hash {
	size_t operator()(const Point &p) const;
};