/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:37:43 by sholz             #+#    #+#             */
/*   Updated: 2024/10/28 13:37:44 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//=======================CONSTRUCTOR/DESTRUCTOR===============================//

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << YELLOW "-> Bureaucrat Contructor called" RESET<< std::endl;
	if (grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat()
{
	std::cout << YELLOW "-> Bureaucrat default Contructor called" RESET << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name), _grade(src._grade)
{
	std::cout << YELLOW "-> Bureaucrat copy Contructor called" RESET << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED "-> Bureaucrat Detructor called" RESET << std::endl;
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << YELLOW "-> Bureaucrat copy Contructor called" RESET<< std::endl;
	if (this != &src) {
		this->_grade = src._grade;
	}
	return *this;
}
//==================================FUNCTIONS======================================//

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void			Bureaucrat::promote()
{
	if((this->_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void			Bureaucrat::demote()
{
	if((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void			Bureaucrat::signForm(std::string name, bool sign)
{
	if (sign)
	{
		std::cout<< this->_name << " signed " << name <<std::endl;
	}
	else
	{
		std::cout<< this->_name << " didn't signed " << name << " because ";
	}
}


//==================================EXCEPTIONS======================================//

const char *	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Peak Beurocracy has already been reached. one can not be grater than 1");
}

const char *	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Lowest Beurocracy has been reached. Below 150 is not worth the paper work.");
}

//==================================Streams======================================//

std::ostream &	operator<<(std::ostream & o, Bureaucrat const &b) {
	o << b.getName() << ", bureaucrat grade : " << b.getGrade();
	return o;
}