#include "Array.hpp"

//==================Constructor Destructor========================//
template<typename T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n];
	for(unsigned int i = 0; i < n; i++)
	{
		_array[i] = 0;
	}
}


template<typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0)
{
	*this = src;
}

template<typename T>
Array<T>::~Array()
{
	delete [] this->_array;
}


//=====================Operations===================//

template<typename T>
Array<T> & Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		delete[] this->_array;
		this->_size = src._size;
		this->_array = new T[src._size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = src._array[i];
	}
	return *this;
}

template<typename T>
T Array<T>::operator[](int n) const
{
	if (n < 0 || n >= static_cast<int>(this->_size))
		throw OutOfBoundException();
	return this->_array[n];
}

template<typename T>
T & Array<T>::operator[](int n)
{
	if (n < 0 || n >= static_cast<int>(this->_size))
		throw OutOfBoundException();
	return this->_array[n];
}

//=================Member Function====================//

template<typename T>
unsigned int Array<T>::size() const
{
	return (this->_size);
}


//========================Exception=======================//

template<typename T>
const char *Array<T>::OutOfBoundException::what() const throw()
{
	return("----------------Out Of Bounds Exception-----------------");
}