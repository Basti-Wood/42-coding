#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	Bureaucrat const*	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(Bureaucrat const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const &src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &rSym);

	Bureaucrat const* getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &src);

#endif