#include "easyfind.hpp"
#include <vector>
// keep C++98-compatible: avoid <array> and initializer lists

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 2);

	try {
		easyfind(v, 6);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		easyfind(v, 7);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	int a[] = {1, 3, 5, 7, 9};
	std::vector<int> arr(a, a + 5);
	try {
		easyfind(arr, 5);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		easyfind(arr, 2);
	} catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}