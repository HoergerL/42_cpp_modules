#include "WrongCat.hpp"


WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "default Constructor WrongCat was called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor WrongCat was called" << std::endl;
}
WrongCat::WrongCat(const WrongCat &cat)
{
	*this = cat;
	std::cout << "Copy Constructor WrongCat was called" << std::endl;
}

WrongCat		&WrongCat::operator=(const WrongCat &cat)
{
	this->type = cat.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "You can hear a loud meow by a WrongCat" << std::endl;
}
