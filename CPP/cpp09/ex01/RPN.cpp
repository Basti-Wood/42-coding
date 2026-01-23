#include "RPN.hpp"
//___________________________Constructor/ Destructor___________________________//
RPN::RPN()
{}
RPN::~RPN()
{}
//___________________________Exception Messages___________________________//
const char* RPN::InvalidExpression::what() const throw()
{
	return ("Error: Invalid Expression.");
}

//___________________________Member functions___________________________//
void	RPN::execute(std::string input)
{
	for(unsigned long i = 0; i < input.size(); i++)
	{
		if(input[i] == ' ')
			i++;
		if(isdigit(input[i]))
		{
			if(input[i+1] != ' ' && i + 1 < input.size())
				throw InvalidExpression();
			_data.push(input[i] - '0');
		}
		else if(input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
		{
			if(_data.size() < 2)
				throw InvalidExpression();
			int b = _data.top();
			_data.pop();
			int a = _data.top();
			_data.pop();
			int result = 0;
			switch(input[i])
			{
				case '+':
					result = a + b;
					break;
				case '-':
					result = a - b;
					break;
				case '*':
					result = a * b;
					break;
				case '/':
					if(b == 0)
						throw InvalidExpression();
					result = a / b;
					break;
			}
			_data.push(result);
		}
		else
			throw InvalidExpression();
	}
	if(_data.size() != 1)
		throw InvalidExpression();
	std::cout << _data.top() << std::endl;
}