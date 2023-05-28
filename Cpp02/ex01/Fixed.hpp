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
};

std::ostream&	operator<<(std::ostream& o, Fixed const &fixed);

#endif