#ifndef CAT_CPP
#define CAT_CPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat	&operator=(const Cat &cat);
	void	makeSound() const;
	Brain	*getBrain() const;
};
#endif