#include <cstdlib>
#include <ctime>
#include <fstream>

int main(int argc, char * argv[]) {
	std::srand(std::time(nullptr));
	char * filename;
	if (argc > 1) {
		filename = argv[1];
	}
	else {
		filename = "file";
	}

	auto fd = std::ofstream(filename, std::ios::binary);
	unsigned int bytes;
	if (argc > 2) {
		bytes = std::stoi(argv[2]);
	}
	else {
		bytes = 1048576;
	}

	char * buffer = new char[bytes];
	for (unsigned int i = 0; i < bytes; i++) {
		buffer[i] = std::rand() / (RAND_MAX / 256 + 1) - 128;
	}
	fd.write(buffer, bytes);
	delete[] buffer;
	fd.close();
	return 0;
}