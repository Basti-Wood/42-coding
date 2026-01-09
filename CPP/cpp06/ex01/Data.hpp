#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

class Data
{
private:
	std::string _objectData;
public:
	Data();
	Data(std::string input);
	Data & operator=(Data const &src);
	~Data();

	std::string getData() const;
};

std::ostream &	operator<<(std::ostream & o, Data const &src);

#endif