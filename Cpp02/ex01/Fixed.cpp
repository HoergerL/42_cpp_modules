#include "Fixed.hpp"
#include <iostream>
#include <math.h>

Fixed::Fixed(void)
{
	std::cout << "Default Constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->_value = integer << Fixed::_nbr_bits;
	//std::cout << this->_value << std::endl;
}

Fixed::Fixed(const float floating)
{
	std::cout << "Floating constructor called" << std::endl;
	this->_value = (int) roundf(floating  * (1 << Fixed::_nbr_bits));
	//std::cout << this->_value << std::endl;
}


Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy Constructor called" << std::endl;
	this->_value = src._value;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &sample)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_value = sample._value;
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits Member Function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits Member Function called" << std::endl;
	this->_value = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float) this->_value / (float) (1 << this->_nbr_bits));
}

int Fixed::toInt( void ) const
{
	return (this->_value >> this->_nbr_bits);
}
std::ostream&	operator<<(std::ostream& o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
}
const int Fixed::_nbr_bits = 8;