#include "PmergeMe.hpp"

//========================Constructor/ Destructor=======================//

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::string arg = av[i];
		std::stringstream ss(arg);
		int num;
		
		if (!(ss >> num) || !ss.eof() || num < 0)
			throw std::invalid_argument("Error: invalid input");
		
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) : _vectorData(other._vectorData), _dequeData(other._dequeData)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vectorData = other._vectorData;
		_dequeData = other._dequeData;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

//========================Helper Functions=======================//
template<typename T>
bool PmergeMe::isSorted(const T& container) const
{
	for(size_t i = 1; i < container.size(); ++i)
	{
		if (container[i - 1] > container[i])
			return false;
	}
	return true;
}


template<typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	if(container.size() <= 1 || isSorted(container))
		return;

	std::vector<std::pair<int, int> > pairs;
	bool hasStraggler = (container.size() % 2 != 0);
	
	if (hasStraggler)
	{
		int straggler = container.back();
	}
	
	size_t pairCount = container.size() / 2;
	for (size_t i = 0; i < pairCount; ++i)
	{
		int a = container[2 * i];
		int b = container[2 * i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	if (pairs.size() > 1)
	{
		T largerElements;
		for (size_t i = 0; i < pairs.size(); ++i)
			largerElements.push_back(pairs[i].first);
		
		mergeInsertSort(largerElements);

		std::vector<std::pair<int, int> > sortedPairs;
		for (size_t i = 0; i < largerElements.size(); ++i)
		{
			for (size_t j = 0; j < pairs.size(); ++j)
			{
				if (pairs[j].first == largerElements[i])
				{
					sortedPairs.push_back(pairs[j]);
					pairs.erase(pairs.begin() + j);
					break;
				}
			}
		}
		pairs = sortedPairs;
	}

	T sorted;
	if (!pairs.empty())
	{
		sorted.push_back(pairs[0].second);
		for (size_t i = 0; i < pairs.size(); ++i)
			sorted.push_back(pairs[i].first);
	}

	for (size_t i = 1; i < pairs.size(); ++i)
	{
		int value = pairs[i].second;
		size_t left = 0;
		size_t right = sorted.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (sorted[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		sorted.insert(sorted.begin() + left, value);
	}
	

	if (hasStraggler)
	{
		size_t left = 0;
		size_t right = sorted.size();
		while (left < right)
		{
			size_t mid = left + (right - left) / 2;
			if (sorted[mid] < straggler)
				left = mid + 1;
			else
				right = mid;
		}
		sorted.insert(sorted.begin() + left, straggler);
	}

	container = sorted;
}
//========================Member functions=======================//

void PmergeMe::sortVector() 
{
	mergeInsertSort(_vectorData);
}

void PmergeMe::sortDeque()
{
	mergeInsertSort(_dequeData);
}

void PmergeMe::printContainer(ContainerType type) const
{
	if (type == VECTOR)
	{
		for (size_t i = 0; i < _vectorData.size(); ++i)
		{
			std::cout << _vectorData[i];
			if (i != _vectorData.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else if (type == DEQUE)
	{
		for (size_t i = 0; i < _dequeData.size(); ++i)
		{
			std::cout << _dequeData[i];
			if (i != _dequeData.size() - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
