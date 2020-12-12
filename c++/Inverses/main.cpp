#include <iostream>
#include <string>
#include "inverses.hpp"

int main(int argc, char * argv[]) {
	if (argc < 2) {
        std::cout << "Too few arguments." << std::endl;
        return 0;
    }

    std::vector<std::string> allInverses = getAllInverses(argv[1]);
    auto size = allInverses.size();
    for (size_t i = 0; i < size; i++) {
        std::cout << allInverses[i] << std::endl;
    }
}