#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"


class Form
{
private:
	const std::string _name;
	bool	_signe;
	const int	_signable;
	const int	_executable;
public:
	Form(std::string name, bool signe, int signable, int executable);
	Form();
	Form(Form const &src);
	~Form();

	std::string getName() const;
	bool getSign() const;
	int getSignable() const;
	int getExecutable() const;

	void beSigned(Bureaucrat &BC);



	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	
};

std::ostream &operator<<(std::ostream &out, Form const &F);

#endif