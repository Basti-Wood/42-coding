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

	bool vecSorted = std::is_sorted(vecCopy.begin(), vecCopy.end());
	bool deqSorted = std::is_sorted(deqCopy.begin(), deqCopy.end());
	std::cout << "Sorted:  " << (vecSorted && deqSorted ? "OK" : "KO") << std::endl;

	std::cout << "Time to process a range of " << _vec.size()
			  << " elements with std::vector : " << usVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
			  << " elements with std::deque  : " << usDeq << " us" << std::endl;
}

/* _________ sorter implementations _________ */

template <typename Container>
static std::vector<Container> split_container(const Container &c)
{
	std::vector<Container> result;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		Container single;
		single.push_back(*it);
		result.push_back(single);
	}
	return result;
}

template <typename Container>
static Container merge_pair(const Container &a, const Container &b)
{
	Container ret;
	typename Container::const_iterator ita = a.begin();
	typename Container::const_iterator itb = b.begin();
	while (ita != a.end() && itb != b.end())
	{
		if (*ita <= *itb)
			ret.push_back(*ita++);
		else
			ret.push_back(*itb++);
	}
	while (ita != a.end())
		ret.push_back(*ita++);
	while (itb != b.end())
		ret.push_back(*itb++);
	return ret;
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &c)
{
	std::stack<Container> conA;
	std::stack<Container> conB;
	Container popA;
	Container popB;
	Container pushcon;
	bool PushConA = false;

	std::vector<Container> singles = split_container(c);
	for (std::size_t i = 0; i < singles.size(); ++i)
		conA.push(singles[i]);

	while(conA.size() > 1 || conB.size() > 1)
	{
		while(PushConA && conB.size() > 1)
		{
			popA = conB.top(); conB.pop();
			popB = conB.top(); conB.pop();
			pushcon = merge_pair(popA, popB);
			conA.push(pushcon);
			if (conB.size() <= 1)
				PushConA = false;
		}
		while(!PushConA && conA.size() > 1)
		{
			popA = conA.top(); conA.pop();
			popB = conA.top(); conA.pop();
			pushcon = merge_pair(popA, popB);
			conB.push(pushcon);
			if (conA.size() <= 1)
				PushConA = true;
		}
	}
	if (conA.size() == 1 && conB.empty())
		c = conA.top();
	else if (conB.size() == 1 && conA.empty())
		c = conB.top();
	else if (conA.size() == 1 && conB.size() == 1)
		c = merge_pair(conA.top(), conB.top());
}

template <typename Container>
void PmergeMe::printContainer(const std::string &prefix, const Container &c)
{
	std::cout << prefix;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		if (it != c.begin())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}