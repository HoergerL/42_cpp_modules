#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int		_value;
	static const int nbr_bits;

public:
	Fixed(void);
	Fixed(Fixed const & src);
	~Fixed(void);
	Fixed	&operator=(Fixed const &sample);
	int getRawBits( void ) const;
	void setRawBits( int const raw );

};

#endif