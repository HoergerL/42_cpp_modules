#include "Dog.hpp"


Dog::Dog()
{
	type = "Dog";
	std::cout << "default Constructor Dog was called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor Dog was called" << std::endl;
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
	std::cout << "Copy Constructor Dog was called" << std::endl;
}

Dog		&Dog::operator=(const Dog &dog)
{
	this->type = dog.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "You hear a bark, it's a dog" << std::endl;
}