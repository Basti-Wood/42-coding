#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaceString(const std::string& str, const std::string& toReplace, const std::string& replaceWith) 
{
	if (toReplace.empty()) {
		return str;
	}
	
	std::string result;
	size_t pos = 0;
	size_t lastPos = 0;

	while ((pos = str.find(toReplace, lastPos)) != std::string::npos) {
		result += str.substr(lastPos, pos - lastPos);
		result += replaceWith;
		lastPos = pos + toReplace.length();
	}
	result += str.substr(lastPos);
	
	return result;
}


int main(int argc, char** argv) 
{
	if (argc != 4) {
		std::cerr << "Usage: " << argv[0] << " <input_file> <String_to_replace> <String_to_replace_with>" << std::endl;
		return 1;
	}
	std::string inputFileName = argv[1];
	std::string strToReplace = argv[2];
	std::string strToReplaceWith = argv[3];
	std::ifstream inputFile(inputFileName.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open file " << inputFileName << std::endl;
		return 1;
	}
	std::stringstream buffer;
	buffer << inputFile.rdbuf();
	std::string fileContent = buffer.str();
	inputFile.close();

	std::string modifiedContent = replaceString(fileContent, strToReplace, strToReplaceWith);
	
	std::string outputFileName = inputFileName + ".replace";
	std::ofstream outputFile(outputFileName.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create output file " << outputFileName << std::endl;
		return 1;
	}

	outputFile << modifiedContent;
	outputFile.close();
	
	std::cout << "File processing complete. Output written to: " << outputFileName << std::endl;
	return 0;
}