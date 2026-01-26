#include "PmergeMe.hpp"
#include <iomanip>
#include <ctime>

void printTime(std::string containerType, std::clock_t time, int elements)
{
	double clock_per_us = static_cast<double>(CLOCKS_PER_SEC) / 1000000;
	double timeInUs = time / clock_per_us;

	std::cout << "Time to process a range of " << elements << " elements with std::" << containerType << " : ";
	std::cout << std::fixed;
	std::cout.precision( 5 );
	std::cout << timeInUs << " us" << std::endl;
}


int main(int i, char **c)
{
	if (i < 2)
	{
		std::cerr << "Usage: ./PmergeMe [positive integers...]" << std::endl;
		return 1;
	}
	
		PmergeMe pmergeMe(i, c);

		std::cout << "Before: ";
		pmergeMe.printContainer(VECTOR);
		std::clock_t vstart = std::clock();
		pmergeMe.sortVector();
		std::clock_t vectorTime = std::clock() - vstart;

		std::clock_t dstart = std::clock();
		pmergeMe.sortDeque();
		std::clock_t dequeTime = std::clock() - dstart;

		std::cout << "After:  ";
		pmergeMe.printContainer(VECTOR);
		
		printTime("vector", vectorTime, i - 1);
		printTime("deque", dequeTime, i - 1);

	return 0;
}



/*
time testing
int main() {
    struct timeval start, end;
    gettimeofday(&start, NULL);

    // Code to measure
    for (int i = 0; i < 1000000; ++i);

    gettimeofday(&end, NULL);
    double duration = (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
    std::cout << "Duration: " << duration << " microseconds" << std::endl;

    return 0;
}
	*/