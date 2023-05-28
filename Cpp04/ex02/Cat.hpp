#ifndef CAT_CPP
#define CAT_CPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
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