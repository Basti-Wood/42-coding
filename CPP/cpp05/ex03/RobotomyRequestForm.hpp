#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	Bureaucrat const*	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(Bureaucrat const& target);
	RobotomyRequestForm(RobotomyRequestForm const &src);
	~RobotomyRequestForm();

	RobotomyRequestForm &	operator=(RobotomyRequestForm const &rSym);

	Bureaucrat const* getTarget() const;
	void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &src);

#endif