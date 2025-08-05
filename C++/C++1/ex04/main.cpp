#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) 
{
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << std::endl;
		return 1;
	}
	std::ifstream inputFile(argv[1]);
	std::string line;
	if (!inputFile) {
		std::cerr << "Error opening input file: " << argv[1] << std::endl;
		return 1;
	}
	std::ofstream outputFile(argv[2]);
	if (!outputFile) {
		std::cerr << "Error opening output file: " << argv[2] << std::endl;
		return 1;
	}
	while (std::getline(inputFile, line)) {
		outputFile << line;
	}
	return 0;
}