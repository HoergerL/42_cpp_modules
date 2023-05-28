#include "Dog.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Animal.hpp"

int main()
{
	{
		int num_animals = 5;
		Animal *animals[num_animals];
		// creation
		for(int i = 0; i < num_animals; i++) 
		{
			if (i < num_animals / 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}

		// make Sound
		for (int i = 0; i < num_animals; i++)
			animals[i]->makeSound();

		// deletion
		for(int i = 0; i < num_animals; i++)
			delete animals[i];
		std::cout << std::endl << "###############################" << std::endl << std::endl;
	}
	{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Dog* a = new Dog();
	const Dog* b = new Dog(*a);

	std::cout << a->getBrain() << std::endl;
	std::cout << b->getBrain() << std::endl; // Addresses are different if deep copy
	delete j;//should not create a leak
	delete i;
	delete a;
	delete b;
	return 0;
	}
}