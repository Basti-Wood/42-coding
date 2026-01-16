#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <exception>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
public:
	Span(unsigned int u);
	Span();
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(int num);
	int longestSpan();
	int shortestSpan();
	void fillSpan(unsigned int number);

	class ValueOverflow : public std::exception
	{
		virtual const char *what() const throw();
	};
	class SpanNotFound : public std::exception
	{
		virtual const char *what() const throw();
	};
};

int randomint(int min, int max);
#endif