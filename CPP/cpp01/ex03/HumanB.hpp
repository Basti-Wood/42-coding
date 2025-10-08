#include "Weapon.hpp"
#include <string>
#ifndef HUMANB_HPP
#define HUMANB_HPP
class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string name);
		~HumanB();
		void setWeapon(Weapon &weapon);
		void attack() const;
};
#endif