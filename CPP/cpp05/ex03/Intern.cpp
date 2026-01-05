#include "Intern.hpp"

//=======================Constructor Destructor=============================//

Intern::Intern() {
	std::cout << "[C] Intern default constructor called." << std::endl;
}

Intern::Intern(Intern const &src) {
	std::cout << "[C] Intern copy constructor called." << std::endl;
	*this = src;
}

Intern::~Intern() {
	std::cout << "[D] Intern default destructor called." << std::endl;
}

Intern &	Intern::operator=(Intern const &rSym) {
	(void)rSym;
	return *this;
}


//=============================Private Functions====================================//

	AForm	*Intern::_makePresidental(Bureaucrat & target) const
	{
		AForm *	form = new PresidentialPardonForm(target);
		return form;
	}
	AForm	*Intern::_makeRobotomy(Bureaucrat & target) const
	{
		AForm *	form = new RobotomyRequestForm(target);
		return form;
	}
	AForm	*Intern::_makeShrubbery(Bureaucrat & target) const
	{
		AForm *	form = new ShrubberyCreationForm(target);
		return form;
	}


//============================Functions============================================//



AForm *Intern::makeForm(std::string FormName, Bureaucrat & target) const
{
	if(FormName == "robotomy request")
		return(_makeRobotomy(target));
	else if(FormName == "presidental pardon")
		return(_makePresidental(target));
	else if(FormName == "shrubbery creation")
		return(_makeShrubbery(target));
	else
	{
		throw Intern::WrongNameException();
		return NULL;
	}
}



//=================================EXCEPTIONS==========================================//

const char *	Intern::WrongNameException::what() const throw() {
	return ("Form Does not Exist. only 'robotomy request', 'presidental pardon' and 'shrubbery creation'");
}