#pragma once

#include "consts.hpp"
#include <unordered_set>

struct pair_hash {
    size_t operator()(const Point &p) const {
        auto first = (unsigned long long)p.first << 32;
        return std::hash<unsigned long long>{}(first + p.second);
    }
};