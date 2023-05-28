#ifndef ARAY_HPP
#define ARAY_HPP

#include <iostream>

template < typename T>
class Array
{
private:
	T *_arr;
	unsigned int _len;

public:
	Array()
	{
		this->_len = 0;
	}

	Array(unsigned int n)
	{
		this->_len = n;
		this->_arr = new T[n];
	}

	Array(const Array &arr)
	{
		*this = arr;
	}

	~Array() 
	{
		if (this->_len != 0)
			delete this->_arr;
	}

	Array &operator=(Array &array)
	{
		if (this->_len != 0)
			delete this->_arr;
		this->_len = array._len;
		this->_arr = new T[this->_len];
		for (unsigned int i = 0; i < this->_len; i++)
		{
			this->_arr[i] = array[i];
		}
		return (*this);
	}

	T& operator[](unsigned int el)
	{
		if (!(el < this->_len))
			throw std::exception();
		return (this->_arr[el]);
	}

	unsigned int	size()
	{
		return (this->_len);
	}

};
#endif