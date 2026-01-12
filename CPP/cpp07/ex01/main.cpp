#include "iter.hpp"



int	main() {
	char	array1[] = {'a', 'b', 'c', 'd'};
	int		array2[] = {1, 2, 3, 4};
	bool	array3[] = {true, false, false, true};

	iter(array1, 4, printval<char>);
	iter(array2, 4, printval<int>);
	iter(array3, 4, printval<bool>);
	return 0;
}