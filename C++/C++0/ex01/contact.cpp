#include "contact.hpp"

Contact::Contact(void) : _firstname(""),
						_lastname(""),
						_nickname(""),
						_number(""),
						_secret("") {
	return;
}

Contact::~Contact(void) {
	return;
}

void Contact::setFirstName(const std::string& firstName){
	this->_firstname = firstName;
}

void Contact::setLastName(const std::string& lastName){
	this->_lastname = lastName;
}

void Contact::setNickname(const std::string& nickname){
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string& phoneNumber){
	this->_number = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret){
	this->_secret = darkestSecret;
}

bool Contact::isEmpty() const {
	if (this->_firstname.empty() && this->_lastname.empty() &&
		this->_nickname.empty() && this->_number.empty() &&
		this->_secret.empty()) {
		return true;
	} 
	return false;
}

std::string Contact::getFirstName() const {
	return this->_firstname;
}
std::string Contact::getLastName() const{
	return this->_lastname;
}
std::string Contact::getNickname() const	{
	return this->_nickname;
}
std::string Contact::getPhoneNumber() const{
	return this->_number;
}
std::string Contact::getDarkestSecret() const{
	return this->_secret;
}
bool Contact::displayContactInfo() const{
	if (this->isEmpty())
		return (false);
	std::cout	<< "+ First name\t: "	<< this->getFirstName()	<< std::endl
				<< "+ Last name\t: "	<< this->getLastName()	<< std::endl
				<< "+ Nickname\t: "		<< this->getNickname()	<< std::endl
				<< "+ Phone number\t: "	<< this->getPhoneNumber() 	<< std::endl
				<< "+ Darkest secret: "	<< this->getDarkestSecret()	<< std::endl;
	return (true);
}
