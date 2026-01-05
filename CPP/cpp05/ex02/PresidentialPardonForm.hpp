#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	Bureaucrat const*	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(Bureaucrat const& target);
	PresidentialPardonForm(PresidentialPardonForm const &src);
	~PresidentialPardonForm();

	PresidentialPardonForm &	operator=(PresidentialPardonForm const &rSym);

	Bureaucrat const* getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &src);

#endif