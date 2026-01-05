#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();

		Bureaucrat &	operator=(Bureaucrat const &rSym);
		std::string	getName() const;
		int			getGrade() const;

		void			promote();
		void			demote();
		void			signForm(std::string name, bool sign);

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

std::ostream &operator<<(std::ostream &out, Bureaucrat const &b);

#endif