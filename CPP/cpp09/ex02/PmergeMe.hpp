#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <utility>

enum ContainerType
{
	VECTOR,
	DEQUE
};

class PmergeMe
{
	private:
	std::vector<int> _vectorData;
	std::deque<int> _dequeData;
	
	template<typename T>
	void mergeInsertSort(T& container);
	template<typename T>
	bool isSorted(const T& container) const;
	
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void sortVector();
		void sortDeque();
		void printContainer(ContainerType type) const;
};

#endif