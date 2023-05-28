#include "WrongDog.hpp"


WrongDog::WrongDog()
{
	type = "WrongDog";
	std::cout << "default Constructor WrongDog was called" << std::endl;
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor WrongDog was called" << std::endl;
}
WrongDog::WrongDog(const WrongDog &dog)
{
	*this = dog;
	std::cout << "Copy Constructor WrongDog was called" << std::endl;
}

WrongDog		&WrongDog::operator=(const WrongDog &dog)
{
	this->type = dog.type;
	return (*this);
}

void	WrongDog::makeSound() const
{
	std::cout << "You hear a bark, it's a WrongDog" << std::endl;
}