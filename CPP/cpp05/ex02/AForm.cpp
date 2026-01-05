#include "AForm.hpp"

//=======================CONSTRUCTOR/DESTRUCTOR===============================//

AForm::AForm(std::string name, bool signe, int signable, int executable)
    : _name(name), _signe(signe), _signable(signable), _executable(executable)
	{
		std::cout << YELLOW "AForm Constructor has been Called" RESET << std::endl;
	}

	AForm::AForm()
		: _name("default"), _signe(false), _signable(150), _executable(150)
	{
		std::cout << YELLOW "AForm Default Constructor has been Called" RESET << std::endl;
	}

	AForm::AForm(AForm const &src)
	: _name(src._name), _signe(src._signe), _signable(src._signable), _executable(src._executable)
	{
		std::cout << YELLOW "AForm Copy Constructor has been Called" RESET << std::endl;
	}

	AForm::~AForm()
	{
		std::cout << RED "AForm Destructor has been Called" RESET << std::endl;
	}

//==================================EXCEPTIONS======================================//

const char *	AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high.");
}

const char *	AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low.");
}

const char *	AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed.");
}

AForm &	AForm::operator=(AForm const &rSym)
{
	if (this != &rSym) {
		this->_signe = rSym._signe;
	}
	return *this;
}


//==================================Functions======================================//

void AForm::beSigned(Bureaucrat &BC)
{
	if(_signe)
	{
		std::cout << " AForm was Signed " << std::endl;
		return;
	}
	else if (BC.getGrade() > this->_signable)
	{
		BC.signForm(this->_name, this->_signe);
		throw AForm::GradeTooLowException();
		return;
	}
	else
	{
		this->_signe = true;
		BC.signForm(this->_name, this->_signe);
		return;
	}
}

std::string AForm::getName() const
{
	return this->_name;
}
bool AForm::getSign() const
{
	return this->_signe;
}
int AForm::getSignable()const
{
	return this->_signable;
}
int AForm::getExecutable() const
{
	return this->_executable;
}

//======================================//
std::ostream &	operator<<(std::ostream & o, AForm const &F)
{
	o << "AForm Name: "<< F.getName() << '\n';
	o << "AForm Signed: "<< F.getSign() << std::endl;
	o << "AForm Sign Level: "<< F.getSignable() << std::endl;
	o << "AForm Execution Level: "<< F.getExecutable() << std::endl;
	return o;
}