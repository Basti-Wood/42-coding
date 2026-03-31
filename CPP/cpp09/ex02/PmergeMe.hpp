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

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	parseInput(int argc, char **argv);

		static std::vector<std::pair<int, int> >	makeSortedPairs(std::vector<int> &c, std::size_t n);
		static std::vector<std::pair<int, int> >	makeSortedPairs(std::deque<int> &c, std::size_t n);

		static std::vector<std::size_t>			jacobsthalSeq(std::size_t pendSize);

		static void	insertPend(std::vector<int> &chain, const std::vector<std::pair<int, int> > &pairs);
		static void	insertPend(std::deque<int> &chain, const std::vector<std::pair<int, int> > &pairs);

		static void	fordJohnsonSort(std::vector<int> &c);
		static void	fordJohnsonSort(std::deque<int> &c);

		static void	printContainer(const std::string &prefix, const std::vector<int> &c);
		static void	printContainer(const std::string &prefix, const std::deque<int> &c);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void	run(int argc, char **argv);
};
