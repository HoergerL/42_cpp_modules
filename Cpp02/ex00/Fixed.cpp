#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void)
{
	std::cout << "Default Constructor called" << std::endl;
	this->_value = 0;
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
	std::cout << "getRawBits Member Function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits Member Function called" << std::endl;
	this->_value = raw;
}

int const Fixed::nbr_bits = 8;