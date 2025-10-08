/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:37:33 by sholz             #+#    #+#             */
/*   Updated: 2025/09/22 17:37:35 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <string>
# include "contact.hpp"
#include <iostream>

class	PhoneBook {
	private:
		int		_index;
		bool	_abort;
		Contact	_contactList[8];

		std::string	_getInput(std::string const prompt);
		void		_incrementIndex(void);
		bool		_displayContactByIndex(std::string const input) const;
		void		_displayContactTable(void) const;
		void		_printContactInfoToTable(int const index) const;
		void		_printTableString(std::string str) const;

	public:
		PhoneBook();
		~PhoneBook();

		std::string	trimBlank(std::string str);
		bool		addContact(void);
		bool		searchContact(void);
};

#endif
