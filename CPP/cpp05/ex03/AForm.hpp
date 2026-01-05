#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"


class AForm
{
	private:
		const std::string _name;
		bool	_signe;
		const int	_signable;
		const int	_executable;
	public:
		AForm(std::string name, bool signe, int signable, int executable);
		AForm();
		AForm(AForm const &src);
		virtual ~AForm();

		std::string getName() const;
		bool getSign() const;
		int getSignable() const;
		int getExecutable() const;

		void beSigned(Bureaucrat &BC);
		virtual void execute(Bureaucrat const & executor) const = 0;



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
		class FormNotSignedException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		AForm &	operator=(AForm const &rSym);
	};

std::ostream &operator<<(std::ostream &out, AForm const &F);

#endif