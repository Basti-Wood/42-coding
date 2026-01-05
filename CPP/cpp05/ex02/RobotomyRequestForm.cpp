#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", false, 72, 45), _target(NULL)
{
	std::cout << YELLOW "Robotomy Form Default Created" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(Bureaucrat const& target): AForm("Robotomy Request", false, 72, 45), _target(&target)
{
	std::cout << YELLOW "Robotomy Form Created" RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src), _target(src._target)
{
	std::cout << YELLOW "Robotomy Form Copied" RESET << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED "Robotomy Form DESTROYED" RESET << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &rSym)
{
	if (this != &rSym) {
		AForm::operator=(rSym);
		this->_target = rSym._target;
	}
	return *this;
}

Bureaucrat const* RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

std::ostream &	operator<<(std::ostream & o, RobotomyRequestForm const &src)
{
	o << "Form name : " << src.getName() << std::endl;
	o << "Target : " << (src.getTarget() ? src.getTarget()->getName() : "none") << std::endl;
	o << "Signed : ";
	if (src.getSign())
		o << "True" << std::endl;
	else
		o << "False" << std::endl;
	o << "Need to be grade " << src.getSignable() << " to sign it, and grade " << src.getExecutable() << " to execute it.";
	return o;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecutable())
		throw AForm::GradeTooLowException();

	std::cout << "* DRILLING NOISES *" << std::endl;
	std::cout << "* BZZZZZZZ *" << std::endl;
	std::cout << "* VRRRRRRRR *" << std::endl;

	std::srand(std::time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << GREEN << this->_target->getName() << " has been robotomized successfully!" RESET << std::endl;
	else
		std::cout << RED << "Robotomy failed on " << this->_target->getName() << "." RESET << std::endl;
}