#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
public:
  MutantStack();
  MutantStack(const MutantStack &other);
  MutantStack &operator=(const MutantStack &other);
  ~MutantStack();

  typedef typename std::stack<T>::container_type container_type;
  typedef typename container_type::iterator iterator;
  typedef typename container_type::const_iterator const_iterator;

  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

#include "MutantStack.tpp"

#endif