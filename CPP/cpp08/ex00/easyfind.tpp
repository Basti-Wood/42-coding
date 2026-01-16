#include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int toBeFound)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toBeFound);
	if (it == container.end())
		throw ValueNotFound();
	std::cout << "Found: " << *it << std::endl;
}




const char* ValueNotFound::what() const throw()
{
    return "-----------------Value Was Not Found-----------------------";
}