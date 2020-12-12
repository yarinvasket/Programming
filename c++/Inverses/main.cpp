#include <iostream>
#include <string>
#include <fstream>
#include "inverses.hpp"

int main(int argc, char * argv[]) {
	if (argc < 2) {
		std::cout << "Too few arguments." << std::endl;
		return 0;
	}

	std::vector<std::string> allInverses = getAllInverses(argv[1]);
	auto size = allInverses.size();
	if (argc < 3) {
		for (size_t i = 0; i < size; i++) {
			std::cout << allInverses[i] << std::endl;
		}
	}
	else {
		auto fd = std::ofstream(argv[2], std::ios::binary);

		//String to write to the file
		std::string toWrite;
		for (std::size_t i = 0; i < size; i++) {
			toWrite += allInverses[i] + "\n";
		}
		auto buffer = toWrite.data();
		fd.write(buffer, toWrite.length());
		fd.close();
	}
}