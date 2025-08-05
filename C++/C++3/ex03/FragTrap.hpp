#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap
{
	private:
		FragTrap(); // Default constructor is private to prevent its use
	public:
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void attack(const std::string &target);
		void highFivesGuys();
};

#endif // FRAGTRAP_HPP