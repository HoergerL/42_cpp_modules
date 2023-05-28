#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int		main()
{
	int N;

	N = 5;
	Zombie *zombies = zombieHorde(N, "zombie");
	delete[] zombies;
	return (0);
}