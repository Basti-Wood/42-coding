#include "PmergeMe.hpp"

/* _________ canonical form _________ */

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

/* _________ input parsing _________ */

void PmergeMe::parseInput(int argc, char **argv)
{
	std::set<int> seen;

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);
		if (arg.empty())
			throw std::runtime_error("empty argument");

		for (std::size_t j = 0; j < arg.size(); j++)
		{
			if (!std::isdigit(arg[j]))
				throw std::runtime_error("not a positive integer");
		}

		long num = std::atol(argv[i]);
		if (num <= 0 || num > INT_MAX)
			throw std::runtime_error("number out of range");

		int n = static_cast<int>(num);
		if (seen.count(n))
			throw std::runtime_error("duplicate number");
		seen.insert(n);

		_vec.push_back(n);
		_deq.push_back(n);
	}
}



/* _________ public entry point _________ */

void PmergeMe::run(int argc, char **argv)
{
	parseInput(argc, argv);

	std::vector<int> vecCopy(_vec);
	std::deque<int>  deqCopy(_deq);

	printContainer("Before: ", _vec);

	clock_t t0 = clock();
	fordJohnsonSort(vecCopy);
	clock_t t1 = clock();
	double usVec = static_cast<double>(t1 - t0) / CLOCKS_PER_SEC * 1000000.0;

	clock_t t2 = clock();
	fordJohnsonSort(deqCopy);
	clock_t t3 = clock();
	double usDeq = static_cast<double>(t3 - t2) / CLOCKS_PER_SEC * 1000000.0;

	printContainer("After:  ", vecCopy);

	bool vecSorted = true;
	for (std::size_t i = 1; i < vecCopy.size(); i++)
		if (vecCopy[i - 1] > vecCopy[i]) { vecSorted = false; break; }
	bool deqSorted = true;
	for (std::size_t i = 1; i < deqCopy.size(); i++)
		if (deqCopy[i - 1] > deqCopy[i]) { deqSorted = false; break; }
	std::cout << "Sorted:  " << (vecSorted && deqSorted ? "OK" : "KO") << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << usVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << usDeq << " us" << std::endl;
}

/* _________ sorter implementations _________ */

struct PairBySecond {
	bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
		return a.second < b.second;
	}
};

std::vector<std::pair<int, int> > PmergeMe::makeSortedPairs(std::vector<int> &c, std::size_t n)
{
	for (std::size_t i = 0; i < n; i += 2)
		if (c[i] > c[i + 1])
			std::swap(c[i], c[i + 1]);
	std::vector<std::pair<int, int> > pairs;
	for (std::size_t i = 0; i < n; i += 2)
		pairs.push_back(std::make_pair(c[i], c[i + 1]));
	return pairs;
}

std::vector<std::pair<int, int> > PmergeMe::makeSortedPairs(std::deque<int> &c, std::size_t n)
{
	for (std::size_t i = 0; i < n; i += 2)
		if (c[i] > c[i + 1])
			std::swap(c[i], c[i + 1]);
	std::vector<std::pair<int, int> > pairs;
	for (std::size_t i = 0; i < n; i += 2)
		pairs.push_back(std::make_pair(c[i], c[i + 1]));
	return pairs;
}

std::vector<std::size_t> PmergeMe::jacobsthalSeq(std::size_t pendSize)
{
	std::vector<std::size_t> jac;
	jac.push_back(1);
	jac.push_back(3);
	while (jac.back() < pendSize)
	{
		std::size_t j = jac.size();
		jac.push_back(jac[j - 1] + 2 * jac[j - 2]);
	}
	return jac;
}

void PmergeMe::insertPend(std::vector<int> &chain, const std::vector<std::pair<int, int> > &pairs)
{
	std::size_t pendSize = pairs.size() - 1;
	if (pendSize == 0)
		return;
	std::vector<std::size_t> jac = jacobsthalSeq(pendSize);
	std::size_t prevGroupEnd = 0;
	for (std::size_t gi = 0; gi < jac.size() && prevGroupEnd < pendSize; ++gi)
	{
		std::size_t groupEnd = std::min(jac[gi], pendSize);
		for (std::size_t idx = groupEnd; idx > prevGroupEnd; --idx)
			chain.insert(
				std::lower_bound(chain.begin(),
					std::lower_bound(chain.begin(), chain.end(), pairs[idx].second),
					pairs[idx].first),
				pairs[idx].first);
		prevGroupEnd = groupEnd;
	}
}

void PmergeMe::insertPend(std::deque<int> &chain, const std::vector<std::pair<int, int> > &pairs)
{
	std::size_t pendSize = pairs.size() - 1;
	if (pendSize == 0)
		return;
	std::vector<std::size_t> jac = jacobsthalSeq(pendSize);
	std::size_t prevGroupEnd = 0;
	for (std::size_t gi = 0; gi < jac.size() && prevGroupEnd < pendSize; ++gi)
	{
		std::size_t groupEnd = std::min(jac[gi], pendSize);
		for (std::size_t idx = groupEnd; idx > prevGroupEnd; --idx)
			chain.insert(
				std::lower_bound(chain.begin(),
					std::lower_bound(chain.begin(), chain.end(), pairs[idx].second),
					pairs[idx].first),
				pairs[idx].first);
		prevGroupEnd = groupEnd;
	}
}

void PmergeMe::fordJohnsonSort(std::vector<int> &c)
{
	std::size_t n = c.size();
	if (n <= 1)
		return;

	bool hasStraggler = (n % 2 != 0);
	int straggler = 0;
	if (hasStraggler) { straggler = c[n - 1]; c.pop_back(); --n; }

	std::vector<std::pair<int, int> > pairs = makeSortedPairs(c, n);

	std::vector<int> largers;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].second);
	fordJohnsonSort(largers);

	std::sort(pairs.begin(), pairs.end(), PairBySecond());

	std::vector<int> chain;
	chain.push_back(pairs[0].first);
	for (std::size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].second);

	insertPend(chain, pairs);

	if (hasStraggler)
		chain.insert(std::lower_bound(chain.begin(), chain.end(), straggler), straggler);

	c = chain;
}

void PmergeMe::fordJohnsonSort(std::deque<int> &c)
{
	std::size_t n = c.size();
	if (n <= 1)
		return;

	bool hasStraggler = (n % 2 != 0);
	int straggler = 0;
	if (hasStraggler) { straggler = c[n - 1]; c.pop_back(); --n; }

	std::vector<std::pair<int, int> > pairs = makeSortedPairs(c, n);

	std::deque<int> largers;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].second);
	fordJohnsonSort(largers);

	std::sort(pairs.begin(), pairs.end(), PairBySecond());

	std::deque<int> chain;
	chain.push_back(pairs[0].first);
	for (std::size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].second);

	insertPend(chain, pairs);

	if (hasStraggler)
		chain.insert(std::lower_bound(chain.begin(), chain.end(), straggler), straggler);

	c = chain;
}

void PmergeMe::printContainer(const std::string &prefix, const std::vector<int> &c)
{
	std::cout << prefix;
	for (std::size_t i = 0; i < c.size(); ++i)
	{
		if (i != 0) std::cout << " ";
		std::cout << c[i];
	}
	std::cout << std::endl;
}

















void PmergeMe::printContainer(const std::string &prefix, const std::deque<int> &c)
{
	std::cout << prefix;
	for (std::size_t i = 0; i < c.size(); ++i)
	{
		if (i != 0) std::cout << " ";
		std::cout << c[i];
	}
	std::cout << std::endl;
}