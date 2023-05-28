#include "Cat.hpp"


Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << "default Constructor Cat was called" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Destructor Cat was called, Brain was deleted" << std::endl;
}
Cat::Cat(const Cat &cat)
{
	*this = cat;
	//this->brain = cat.brain;
	std::cout << "Copy Constructor Cat was called" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	std::string* src = cat.getBrain()->getIdeas();
	this->type = cat.getType();
	this->brain = new Brain();
	//std::cout << "Assignation overload" << this->brain << std::endl;
	std::string* dest = this->brain->getIdeas();
	for (int i = 0; i < 100; i++)
		dest[i] = src[i];
	return (*this);
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}

void	Cat::makeSound() const
{
	std::cout << "You can hear a loud meow by a cat" << std::endl;
}
