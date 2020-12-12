#include "inverses.hpp"

std::vector<std::string> getAllInverses(std::string str) {
	auto size = str.size();
	if (size <= 1) {
		return std::vector<std::string>({str});
	}

	std::vector<std::string> out;
	for (std::size_t i = 0; i < size; i++) {
		std::string swappedString = str;
		//Swap the first letter with the i'th letter
		if (i != 0) {
			auto c = swappedString[0];
			swappedString[0] = swappedString[i];
			swappedString[i] = c;
		}

		//String of all characters except the first one
		auto trimmed = swappedString.substr(1);

		//Vector of all of the inverses of the trimmed string
		auto subVector = getAllInverses(trimmed);

		auto vecSize = subVector.size();
		auto c = swappedString[0];
		for (std::size_t j = 0; j < vecSize; j++) {
			out.push_back(c + subVector[j]);
		}
	}

	return out;
}