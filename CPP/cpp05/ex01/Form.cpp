#include "Form.hpp"

//=======================CONSTRUCTOR/DESTRUCTOR===============================//

Form::Form(std::string name, bool signe, int signable, int executable)
    : _name(name), _signe(signe), _signable(signable), _executable(executable)
	{
		std::cout << YELLOW "Form Constructor has been Called" RESET << std::endl;
		if (signable < 1 || executable < 1)
			throw Form::GradeTooHighException();
		if (signable > 150 || executable > 150)
			throw Form::GradeTooLowException();
	}

	Form::Form()
		: _name(NULL), _signe(false), _signable(150), _executable(150)
	{
		std::cout << YELLOW "Form Default Constructor has been Called" RESET << std::endl;
	}

	Form::Form(Form const &src)
	: _name(src._name), _signe(src._signe), _signable(src._signable), _executable(src._executable)
	{
		std::cout << YELLOW "Form Copy Constructor has been Called" RESET << std::endl;
	}

	Form::~Form()
	{
		std::cout << RED "Form Destructor has been Called" RESET << std::endl;
	}

//==================================EXCEPTIONS======================================//

const char *	Form::GradeTooHighException::what() const throw() {
	return ("Form Level is too high.");
}

const char *	Form::GradeTooLowException::what() const throw() {
	return ("Form Level is too Low.");
}


//==================================Functions======================================//

void Form::beSigned(Bureaucrat &BC)
{
	if(_signe)
	{
		std::cout << " Form was Signed " << std::endl;
		return;
	}
	else if (BC.getGrade() > this->_signable)
	{
		BC.signForm(this->_name, this->_signe);
		throw Form::GradeTooLowException();
		return;
	}
	else
	{
		this->_signe = true;
		BC.signForm(this->_name, this->_signe);
		return;
	}
}

std::string Form::getName() const
{
	return this->_name;
}
bool Form::getSign() const
{
	return this->_signe;
}
int Form::getSignable()const
{
	return this->_signable;
}
int Form::getExecutable() const
{
	return this->_executable;
}

//======================================//
std::ostream &	operator<<(std::ostream & o, Form const &F)
{
	o << "Form Name: "<< F.getName() << '\n';
	o << "Form Signed: "<< F.getSign() << std::endl;
	o << "Form Sign Level: "<< F.getSignable() << std::endl;
	o << "Form Execution Level: "<< F.getExecutable() << std::endl;
	return o;
}