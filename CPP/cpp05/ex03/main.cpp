#include "Intern.hpp"

int main()
{
	std::cout << CYAN << "=== Creating Bureaucrats ===" << RESET << std::endl;
	Bureaucrat boss("Boss", 1);
	Bureaucrat worker("Worker", 50);
	Bureaucrat lowRank("LowRank", 150);

	std::cout << std::endl << CYAN << "=== Creating Intern ===" << RESET << std::endl;
	Intern intern;

	std::cout << std::endl << CYAN << "=== Creating Forms via Intern ===" << RESET << std::endl;
	AForm *shrubbery = NULL;
	AForm *robotomy = NULL;
	AForm *pardon = NULL;

	try {
		shrubbery = intern.makeForm("shrubbery creation", lowRank);
		std::cout << GREEN << "Created: " << *shrubbery << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		robotomy = intern.makeForm("robotomy request", worker);
		std::cout << GREEN << "Created: " << *robotomy << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	try {
		pardon = intern.makeForm("presidental pardon", boss);
		std::cout << GREEN << "Created: " << *pardon << RESET << std::endl;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	// Test invalid form name
	std::cout << std::endl << CYAN << "=== Testing Invalid Form Name ===" << RESET << std::endl;
	try {
		AForm *invalid = intern.makeForm("invalid form", boss);
		(void)invalid;
	} catch (std::exception &e) {
		std::cout << RED << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << CYAN << "=== Signing and Executing Forms ===" << RESET << std::endl;

	// Shrubbery - sign and execute
	if (shrubbery) {
		std::cout << std::endl << YELLOW << "-- Shrubbery Form --" << RESET << std::endl;
		shrubbery->beSigned(worker);
		boss.executeForm(*shrubbery);
	}

	// Robotomy - sign and execute
	if (robotomy) {
		std::cout << std::endl << YELLOW << "-- Robotomy Form --" << RESET << std::endl;
		robotomy->beSigned(worker);
		boss.executeForm(*robotomy);
	}

	// Presidential Pardon - sign and execute
	if (pardon) {
		std::cout << std::endl << YELLOW << "-- Presidential Pardon Form --" << RESET << std::endl;
		pardon->beSigned(boss);
		boss.executeForm(*pardon);
	}

	// Test execution failure (low grade)
	std::cout << std::endl << CYAN << "=== Testing Execution Failure (Low Grade) ===" << RESET << std::endl;
	if (pardon) {
		try {
			lowRank.executeForm(*pardon);
		} catch (std::exception &e) {
			std::cout << RED << "Error: " << e.what() << RESET << std::endl;
		}
	}

	std::cout << std::endl << CYAN << "=== Cleanup ===" << RESET << std::endl;
	delete shrubbery;
	delete robotomy;
	delete pardon;

	return 0;
}