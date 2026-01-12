#include "iter.hpp"

template<typename T>
void	iter(T *adress, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		f(adress[i]);
}

template<typename T>
void	printval(T &val)
{
	std::cout << val << std::endl;
}