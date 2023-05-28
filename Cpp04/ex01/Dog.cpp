#include "Dog.hpp"


Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "default Constructor Dog was called" << std::endl;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor Dog was called, brain was deleted" << std::endl;
}
Dog::Dog(const Dog &dog)
{
	*this = dog;
	//this->brain = dog.brain;
	std::cout << "Copy Constructor Dog was called" << std::endl;
}

Dog	&Dog::operator=(const Dog &dog)
{
	std::string* src = dog.getBrain()->getIdeas();
	this->type = dog.getType();
	this->brain = new Brain();
	//std::cout << "Assignation overload" << this->brain << std::endl;
	std::string* dest = this->brain->getIdeas();
	for (int i = 0; i < 100; i++)
		dest[i] = src[i];
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "You hear a bark, it's a dog" << std::endl;
}

Brain	*Dog::getBrain() const
{
	return(this->brain);
}