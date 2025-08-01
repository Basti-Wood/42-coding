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
	Zombie(std::string name);
	~Zombie();
	void announce() const;
};
#endif