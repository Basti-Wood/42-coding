#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template<typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;
	
public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	~Array();

	Array &	operator=(Array const &src);
	T		operator[](int n) const;
	T &		operator[](int n);
	unsigned int size() const;
	
	class OutOfBoundException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#include "Array.tpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#endif