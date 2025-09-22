#include "phonebook.hpp"
#include <iomanip>
#include <stdexcept>
#include <string>


PhoneBook::PhoneBook(void) : _index(-1), _abort(false) {
	return ;
}

PhoneBook::~PhoneBook(void) {
	return ;
}

std::string	PhoneBook::_getInput(std::string const prompt)
{
	std::string input;
	std::cout << "Please enter " << prompt << ": " <<std::endl;
	if (!std::getline(std::cin, input) || std::cin.eof()) {
		_abort = true;
		std::cout << std::endl;
		return(std::string());
	}
	input = trimBlank(input);
	return input;
}
void		PhoneBook::_incrementIndex(void)
{
	_index = (_index + 1) % 8;
}

bool		PhoneBook::_displayContactByIndex(std::string const input) const
{
	int			index;

	if (input.length() == 1 && std::isdigit(input[0])) {
		index = input[0] - '0';
		if (index >= 0 && index <= 7) {
			if (this->_contactList[index].displayContactInfo())
				return (true);
			else {
				std::cout << "Error: No record at index [" << index << "]. Please ADD a contact and try again." << std::endl;
				return (false);
			}
		}
	}
	std::cout << "Error: \'" << input << "' is not a valid index (a digit between 0 and 7). Please try again later." << std::endl;
	return (false);
}

void		PhoneBook::_displayContactTable(void) const
{
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "| Index | First Name | Last Name | Nickname |" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; ++i) {
		_printContactInfoToTable(i);
	}
	std::cout << "---------------------------------------------" << std::endl;
}
void		PhoneBook::_printContactInfoToTable(int const index) const
{
	std::cout << "| " << std::setw(5) << index << " | ";
	_printTableString(_contactList[index].getFirstName());
	_printTableString(_contactList[index].getLastName());
	_printTableString(_contactList[index].getNickname());
	std::cout << "|" << std::endl;
}

void		PhoneBook::_printTableString(std::string str) const
{
	if (str.length() > 10) {
		str = str.substr(0, 9) + ".";
	}
	std::cout << std::setw(10) << str << " | ";
}

std::string	PhoneBook::trimBlank(std::string str)
{
	str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
	str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
	return str;
}

bool		PhoneBook::addContact() 
{
	if (_index < 7) {
		_incrementIndex();
	} else {
		std::cout << "Phonebook is full. Overwriting oldest contact." << std::endl;
		_incrementIndex();
	}

	std::string firstName = _getInput("First Name");
	if (_abort) return false;

	std::string lastName = _getInput("Last Name");
	if (_abort) return false;

	std::string nickname = _getInput("Nickname");
	if (_abort) return false;

	std::string phoneNumber = _getInput("Phone Number");
	if (_abort) return false;

	std::string darkestSecret = _getInput("Darkest Secret");
	if (_abort) return false;

	_contactList[_index].setFirstName(firstName);
	_contactList[_index].setLastName(lastName);
	_contactList[_index].setNickname(nickname);
	_contactList[_index].setPhoneNumber(phoneNumber);
	_contactList[_index].setDarkestSecret(darkestSecret);

	return true;
}
void		PhoneBook::displayContact(int index) const
{
	if (index < 0 || index >= 8) {
		std::cout << "Invalid index. Please enter a number between 0 and 7." << std::endl;
		return;
	}

	const Contact& contact = _contactList[index];
	std::cout << "First Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last Name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone Number: " << contact.getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << contact.getDarkestSecret() << std::endl;
}
bool		PhoneBook::searchContact() 
{
	if (_index < 0) {
		std::cout << "No contacts available." << std::endl;
		return false;
	}

	_displayContactTable();

	std::string input = _getInput("Index of the contact to display");
	if (_abort)
		return false;

	return _displayContactByIndex(input);
}