#ifndef CAT_CPP
#define CAT_CPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat(const Cat &cat);
	Cat		&operator=(const Cat &cat);
	void	makeSound() const;
};
#endif