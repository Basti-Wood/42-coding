#include "Fixed.hpp"



Fixed::Fixed() : _raw(0) {
	std::cerr << GREEN "Default constructor called." RESET<< std::endl;
	return;
}

Fixed::Fixed(const Fixed &other) : _raw(other._raw) {
	std::cerr << YELLOW "Copy constructor called." RESET << std::endl;
	return;
}

Fixed::Fixed(const int val) {
	std::cerr << "Int constructor called." << std::endl;
	this->_raw = (val<< _fractionalBits);
}

Fixed::Fixed(const float val) {
	std::cerr << "Float constructor called." << std::endl;
	this->_raw = roundf(val * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cerr << BLUE "Copy assignment operator called."  RESET<< std::endl;
	if ( this != &other )
		this->_raw = other.getRawBits();
	return ( *this );
}

Fixed::~Fixed() {
	std::cerr << RED "Destructor called." RESET << std::endl;
	return;
}
int Fixed::getRawBits() const {
	std::cerr << MAGENTA "getRawBits member function called." RESET << std::endl;
	return this->_raw;
}
void Fixed::setRawBits(int const raw) {
	std::cerr << CYAN "setRawBits member function called." RESET << std::endl;
	this->_raw = raw;
}

float Fixed::toFloat() const {
	return ((float)this->_raw) / (1 << _fractionalBits);
}
int Fixed::toInt() const {
	return this->_raw >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}