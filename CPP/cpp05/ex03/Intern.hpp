#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
private:
	AForm	*_makePresidental(Bureaucrat & target) const;
	AForm	*_makeRobotomy(Bureaucrat & target) const;
	AForm	*_makeShrubbery(Bureaucrat & target) const;
	
public:
	Intern();
	Intern(Intern const &src);
	~Intern();
	Intern &	operator=(Intern const &rSym);


	AForm *makeForm(std::string FormName, Bureaucrat & target) const;

	class WrongNameException : public std::exception {
			public:
				virtual const char *	what() const throw();
		};
};



#endif
