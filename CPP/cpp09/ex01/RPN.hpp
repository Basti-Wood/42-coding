#ifndef RMP_HPP
#define RMP_HPP
#include <stack>
#include <iostream>


class RPN
{
private:
	std::stack<int>	_data;
public:
	RPN();
	~RPN();
	void	execute(std::string input);

	class InvalidExpression : public std::exception {
			const char *what() const throw();
	};

};




#endif