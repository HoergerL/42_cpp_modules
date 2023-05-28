#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal &animal);
	AAnimal	&operator=(const AAnimal &animal);
	AAnimal	*operator=(AAnimal *animal);
	std::string	getType() const;
	virtual void		makeSound() const = 0;

};

#endif