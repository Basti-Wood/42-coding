#include <string>

#ifndef WEAPON_HPP
#define WEAPON_HPP
class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(const std::string &type);
		Weapon();
		~Weapon();
		void setType(const std::string &type);
		std::string getType() const;
};
#endif