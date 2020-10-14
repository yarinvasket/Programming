#include "pair_hash.hpp"

size_t pair_hash::operator()(const Point &p) const {
	auto first = (unsigned long long)p.first << 32;
	return std::hash<unsigned long long>{}(first | p.second);
}