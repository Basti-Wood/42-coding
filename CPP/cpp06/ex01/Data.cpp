#include "Data.hpp"

//=========================CONSTRUCTOR=====================//


Data::Data(std::string input): _objectData(input)
{
	std::cout << "Data Created" << std::endl; 
}

Data::Data()
{
	_objectData = "Default Text";
	std::cout << "Data Created" << std::endl; 
}

Data & Data::operator=(Data const &src)
{
	if(this != &src)
		this->_objectData = src._objectData;
	return *this;
}

Data::~Data()
{
	std::cout << "Destructor used" << std::endl;
}

//=====================GETTER==================//

std::string Data::getData() const
{
	return(_objectData);
}



//=================================================//

std::ostream &	operator<<(std::ostream & o, Data const &src)
{
	o << src.getData();
	return o;
}