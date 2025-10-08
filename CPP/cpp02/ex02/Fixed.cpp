#include "Fixed.hpp"

//=====================Constructors=====================//

Fixed::Fixed() : _raw(0) {
	return;
}

Fixed::Fixed(const Fixed &other) : _raw(other._raw) {
	return;
}

Fixed::Fixed(const int val) {
	this->_raw = (val<< _fractionalBits);
}

Fixed::Fixed(const float val) {
	this->_raw = roundf(val * (1 << _fractionalBits));
}

Fixed::~Fixed() {
	return;
}

//=====================Getters and Setters=====================//
int Fixed::getRawBits() const {
	return this->_raw;
}
void Fixed::setRawBits(int const raw) {
	this->_raw = raw;
}

//=====================Public functions=====================//

float Fixed::toFloat() const {
	return ((float)this->_raw) / (1 << _fractionalBits);
}
int Fixed::toInt() const {
	return this->_raw >> _fractionalBits;
}
Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
	if(lhs < rhs)
		return lhs;
	else
		return rhs;
}
Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
		if(lhs > rhs)
		return lhs;
	else
		return rhs;
}
Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs) {
	if(lhs < rhs)
		return lhs;
	else
		return rhs;
}
Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
	if(lhs > rhs)
		return lhs;
	else
		return rhs;
}
//=====================Operators=====================//
Fixed &Fixed::operator=(Fixed const & src) {
	if (this != &src) {
		this->_raw = src._raw;
	}
	return *this;
}

bool Fixed::operator>(Fixed const & rhs) const {
	return this->_raw > rhs._raw;
}
bool Fixed::operator<(Fixed const & rhs) const {
	return this->_raw < rhs._raw;
}
bool Fixed::operator>=(Fixed const & rhs) const {
	return this->_raw >= rhs._raw;
}
bool Fixed::operator<=(Fixed const & rhs) const {
	return this->_raw <= rhs._raw;
}
bool Fixed::operator==(Fixed const & rhs) const {
	return this->_raw == rhs._raw;
}
bool Fixed::operator!=(Fixed const & rhs) const {
	return this->_raw != rhs._raw;
}
Fixed Fixed::operator+(Fixed const & rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(Fixed const & rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(Fixed const & rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(Fixed const & rhs) const {
	if (rhs._raw == 0) {
		std::cerr << "Error: Division by zero." << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / rhs.toFloat());
}
Fixed &Fixed::operator++() {
	++this->_raw;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}
Fixed &Fixed::operator--() {
	--this->_raw;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

