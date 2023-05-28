#include "WrongAnimal.hpp"

	WrongAnimal::WrongAnimal()
	{
		type = "WrongAnimal";
		std::cout << "default Constructor WrongAnimal was called" << std::endl;
	}
	WrongAnimal::~WrongAnimal()
	{
		std::cout << "Destructor WrongAnimal was called" << std::endl;
	}
	WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
	{
		*this = wrongAnimal;
		std::cout << "Copy Constructor WrongAnimal was called" << std::endl;
	}
	WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &wrongAnimal)
	{
		this->type = wrongAnimal.getType();
		return (*this);
	}
	std::string	WrongAnimal::getType() const
	{
		return (this->type);
	}
	
	void	WrongAnimal::makeSound() const
	{
		std::cout << "You hear some strange sound, it's definitely an WrongAnimal" << std::endl;
	}
