#include <iostream>
#include <string>

#ifndef HARL_HPP
#define HARL_HPP


class Harl
{
	private:
		void _debug();
		void _info();
		void _warning();
		void _error();
	public:
		Harl();
		~Harl();

		void complain(const std::string &level);
};


#endif // HARL_HPP