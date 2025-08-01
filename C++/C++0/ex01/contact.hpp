#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>

class Contact {
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_number;
		std::string	_secret;
	public:
		Contact();
		~Contact();

		bool isEmpty() const;
		void setFirstName(const std::string& firstName);
		void setLastName(const std::string& lastName);
		void setNickname(const std::string& nickname);
		void setPhoneNumber(const std::string& phoneNumber);
		void setDarkestSecret(const std::string& darkestSecret);

		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		bool displayContactInfo() const;
};

#endif