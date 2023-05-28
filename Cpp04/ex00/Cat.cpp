#include "Cat.hpp"


Cat::Cat()
{
	type = "Cat";
	std::cout << "default Constructor Cat was called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat was called" << std::endl;
}
Cat::Cat(const Cat &cat)
{
	*this = cat;
	std::cout << "Copy Constructor Cat was called" << std::endl;
}

Cat		&Cat::operator=(const Cat &cat)
{
	this->type = cat.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "You can hear a loud meow by a cat" << std::endl;
}
