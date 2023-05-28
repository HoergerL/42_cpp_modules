#include "Animal.hpp"

	Animal::Animal()
	{
		type = "Animal";
		std::cout << "default Constructor Animal was called" << std::endl;
	}
	Animal::~Animal()
	{
		std::cout << "Destructor Animal was called" << std::endl;
	}
	Animal::Animal(const Animal &animal)
	{
		//std::string* src = animal.getBrain()->getIdeas();
		*this = animal;
		//std::string* dest = this->brain->getIdeas();
		std::cout << "Copy Constructor Animal was called" << std::endl;
	}

	Animal	&Animal::operator=(const Animal &animal)
	{
		this->type = animal.getType();
		return (*this);
	}

	std::string	Animal::getType() const
	{
		return (this->type);
	}
	
	void	Animal::makeSound() const
	{
		std::cout << "You hear some strange sound, it's definitely an animal" << std::endl;
	}
