#include <iostream>
#include <string>
#include "stuff.hpp"

int main(int argc, char * argv[]) {
	if (argc <= 1) {
		std::cout << "Yo dawg you have to give this prigram an argument parameter" << std::endl;
		return 0;
	}

	try {
		double num = f(std::stod(argv[1]));
		std::cout << num << std::endl;
		num = g(num);
		std::cout << num << std::endl;
	} catch (const std::invalid_argument & e) {
		std::cout << "You dawg you have to like give this a valid number like -2.835 okay?" << std::endl;
	}
}