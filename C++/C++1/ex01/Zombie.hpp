#include <iostream>
#include <string>


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
class Zombie
{
private:
	std::string _name;
	std::string _GetName() const;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce() const;
	void setName(std::string name);
};
#endif