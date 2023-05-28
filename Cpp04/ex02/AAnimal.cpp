#include "AAnimal.hpp"

	AAnimal::AAnimal()
	{
		type = "AAnimal";
		std::cout << "default Constructor AAnimal was called" << std::endl;
	}
	AAnimal::~AAnimal()
	{
		std::cout << "Destructor AAnimal was called" << std::endl;
	}
	AAnimal::AAnimal(const AAnimal &animal)
	{
		//std::string* src = animal.getBrain()->getIdeas();
		*this = animal;
		//std::string* dest = this->brain->getIdeas();
		std::cout << "Copy Constructor AAnimal was called" << std::endl;
	}

	AAnimal	&AAnimal::operator=(const AAnimal &animal)
	{
		this->type = animal.getType();
		return (*this);
	}

	std::string	AAnimal::getType() const
	{
		return (this->type);
	}
