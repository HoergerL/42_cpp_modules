#ifndef DOG_CPP
#define DOG_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
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