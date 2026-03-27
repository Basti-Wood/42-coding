#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <stdexcept>
#include <set>
#include <stack>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	parseInput(int argc, char **argv);

		template <typename Container>
		static void	fordJohnsonSort(Container &c);

		template <typename Container>
		static void	printContainer(const std::string &prefix, const Container &c);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);
};
