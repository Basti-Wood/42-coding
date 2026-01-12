#ifndef ITER_HPP_
#define ITER_HPP_

#include <iostream>
#include <string>
#include "iter.cpp"

template<typename T>
void	iter(T *address, int len, void (*f)(T&));

template<typename T>
void	printval(T &val);



#endif