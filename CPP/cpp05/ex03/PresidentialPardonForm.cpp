#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", false, 25, 5), _target(NULL)
{
	std::cout << YELLOW "Presidential Pardon Form Default Created" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(Bureaucrat const& target): AForm("Presidential Pardon", false, 25, 5), _target(&target)
{
	std::cout << YELLOW "Presidential Pardon Form Created" RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): AForm(src), _target(src._target)
{
	std::cout << YELLOW "Presidential Pardon Form Copied" RESET << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED "Presidential Pardon Form DESTROYED" RESET << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &rSym)
{
	if (this != &rSym) {
		AForm::operator=(rSym);
		this->_target = rSym._target;
	}
	return *this;
}

Bureaucrat const* PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

std::ostream &	operator<<(std::ostream & o, PresidentialPardonForm const &src)
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSign())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecutable())
		throw AForm::GradeTooLowException();

	std::cout << this->_target->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}