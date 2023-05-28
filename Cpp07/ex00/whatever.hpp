#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

class Awesome 
	{
	public:
		Awesome( int n ) : _n( n ) {}
		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
		int get() const {return _n; }
	private:
		int _n;
	};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template <typename T>
void	swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T	max(T x, T y)
{
	return (x > y ? x : y);
}

template <typename T>
T	min(T x, T y)
{
	return (x >= y ? y : x);
}

#endif