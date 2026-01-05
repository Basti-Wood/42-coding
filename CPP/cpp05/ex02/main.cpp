#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	// Executors
	Bureaucrat Donald("Donald", 1);
	Bureaucrat Greta("Greta", 25);
	Bureaucrat Arnold("Arnold", 45);

	// Low grade bureaucrats (cannot execute/sign)
	Bureaucrat Mickey("Mickey", 150);
	Bureaucrat OHair("OHair", 146);
	Bureaucrat Terminator("Terminator", 100);

	// Targets for the forms (Bureaucrats)
	Bureaucrat Jeffry("Jeffry", 100);
	Bureaucrat Balcony("Balcony", 100);
	Bureaucrat Murphy("Alex James Murphy", 100);

	PresidentialPardonForm pardon(Jeffry);
	ShrubberyCreationForm shrub(Balcony);
	RobotomyRequestForm robot(Murphy);

	std::cout << std::endl << CYAN "=== Worthy Bureaucrats Sign Forms ===" RESET << std::endl;
	try {
		pardon.beSigned(Donald);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		shrub.beSigned(Greta);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		robot.beSigned(Arnold);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << std::endl << CYAN "=== Worthy Bureaucrats Execute Forms ===" RESET << std::endl;
	Donald.executeForm(pardon);
	Greta.executeForm(shrub);
	Arnold.executeForm(robot);

	std::cout << std::endl << CYAN "=== Non-Worthy Bureaucrats Try to Execute ===" RESET << std::endl;
	Mickey.executeForm(pardon);
	OHair.executeForm(shrub);
	Terminator.executeForm(robot);

	// Create new unsigned forms to test signing by low grade
	Bureaucrat AnotherCriminal("Another Criminal", 100);
	Bureaucrat Garden("Garden", 100);
	Bureaucrat AnotherTarget("Another Target", 100);

	PresidentialPardonForm pardon2(AnotherCriminal);
	ShrubberyCreationForm shrub2(Garden);
	RobotomyRequestForm robot2(AnotherTarget);

	std::cout << std::endl << CYAN "=== Non-Worthy Bureaucrats Try to Sign ===" RESET << std::endl;
	try {
		pardon2.beSigned(Mickey);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		shrub2.beSigned(OHair);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try {
		robot2.beSigned(Terminator);
	} catch (std::exception &e) {
		std::cout << RED << e.what() << RESET << std::endl;
	}

	return 0;
}