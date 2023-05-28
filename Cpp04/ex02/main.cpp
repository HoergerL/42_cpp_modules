#include "Dog.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main()
{
	{
		int num_animals = 4;
		AAnimal *animals[num_animals];
		for(int i = 0; i < num_animals; i++)
		{
			if (i < num_animals / 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < num_animals; i++)
		{
			animals[i]->makeSound();
		}
		for(int i = 0; i < num_animals; i++)
		{
			delete animals[i];
		}
		std::cout << std::endl << "###############################" << std::endl << std::endl;
	}
	{
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	const Dog* a = new Dog();
	const Dog* b = new Dog(*a);
	//const AAnimal animal = new AAnimal(); // does not work for abstract class

	std::cout << a->getBrain() << std::endl;
	std::cout << b->getBrain() << std::endl; // Addresses are different if deep copy
	delete j;//should not create a leak
	delete i;
	delete a;
	delete b;
	return 0;
	}
}