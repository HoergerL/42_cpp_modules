#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int		_value;
	static const int _nbr_bits;

public:
	Fixed(void);
	Fixed(const int integer);
	Fixed(const float floating);
	Fixed(Fixed const & src);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;

	Fixed	&operator=(Fixed const &sample);

	//comparison operators
	bool	operator>(Fixed const &sample);
	bool	operator>=(Fixed const &sample);
	bool	operator<=(Fixed const &sample);
	bool	operator<(Fixed const &sample);
	bool	operator!=(Fixed const &sample);
	bool	operator==(Fixed const &sample);

	//arithmetic operators
	Fixed	operator+(Fixed const &sample);
	Fixed	operator-(Fixed const &sample);
	Fixed	operator*(Fixed const &sample);
	Fixed	operator/(Fixed const &sample);

	//increment/decrement
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	//min/max
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

};

std::ostream&	operator<<(std::ostream& o, Fixed const &fixed);

#endif