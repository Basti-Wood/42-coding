#include "phonebook.hpp"

int main() {
	PhoneBook phonebook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command) || std::cin.eof()) {
			std::cout << "Exiting..." << std::endl;
			break;
		}
		command = phonebook.trimBlank(command);

		if (command == "ADD") {
			if (!phonebook.addContact()) {
				std::cout << "Contact addition aborted." << std::endl;
			}
		} else if (command == "SEARCH") {
			if (!phonebook.searchContact()) {
				std::cout << "Search aborted or no contacts available." << std::endl;
			}
		} else if (command == "EXIT") {
			std::cout << "Exiting phonebook." << std::endl;
			break;
		} else {
			std::cout << "Unknown command. Please use ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}