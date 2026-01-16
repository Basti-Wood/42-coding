#include "Span.hpp"


//______________________________Constructor Destructor_________________//
Span::Span(unsigned int u)
{
	_maxSize = u;
}
Span::Span()
{
	_maxSize = 10;
}
Span::Span(const Span &src)
{
	this->_maxSize = src._maxSize;
	this->_numbers = src._numbers;
}
Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return *this;
	this->_maxSize = src._maxSize;
	this->_numbers = src._numbers;
	return *this;
}
Span::~Span()
{
	std::cout << "Detructor called" << std::endl;
}


//______________________Functions_____________________//

void Span::addNumber(int num)
{
	if(_numbers.size() == _maxSize)
		throw ValueOverflow();
	else
		this->_numbers.push_back(num);
}


int Span::longestSpan()
{
	if(this->_numbers.size() < 2)
		throw SpanNotFound();
	std::vector<int>::iterator it_max;
	std::vector<int>::iterator it_min;
	it_max = std::max_element(this->_numbers.begin(), this->_numbers.end());
	it_min = std::min_element(this->_numbers.begin(), this->_numbers.end());
	return (*it_max - *it_min);
}
int Span::shortestSpan()
{
	if(this->_numbers.size() < 2)
		throw SpanNotFound();
	std::vector<int> tmp = this->_numbers;
	std::sort(tmp.begin(), tmp.end());
	int minSpan = tmp.at(1) - tmp.at(0);
	for (std::size_t i = 2; i < tmp.size(); ++i) {
		int diff = tmp[i] - tmp[i - 1];
		if (diff < minSpan)
			minSpan = diff;
	}
	return minSpan;
}

void Span::fillSpan(unsigned int number)
{
    for (unsigned int i = 0; i < this->_maxSize && i < number; ++i)
        this->addNumber(randomint(1, 1000));
}

//--------------------------Exceptions-------------------//
const char* Span::ValueOverflow::what() const throw()
{
    return "-----------------No more space in the container-----------------------";
}
const char* Span::SpanNotFound::what() const throw()
{
    return "-----------------No Span Found in the container-----------------------";
}