#ifndef DOG_CPP
#define DOG_CPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain *brain;

public:
	Dog();
	~Dog();
	Dog(const Dog &dog);
	Dog	&operator=(const Dog &dog);
	void	makeSound() const;
	Brain	*getBrain() const;
};
#endif