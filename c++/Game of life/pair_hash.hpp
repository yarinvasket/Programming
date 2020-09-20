#pragma once

#include <unordered_set>

struct pair_hash {
    size_t operator()(const std::pair<unsigned int, unsigned int> &p) const {
        unsigned long long first = (unsigned long long)p.first << 32;
        return std::hash<unsigned long long>{}(first + p.second);
    }
};