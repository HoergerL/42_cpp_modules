#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 0)
	{
		std::cout << "wrong input" << std::endl;
		return NULL;
	}
	Zombie *zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombieHorde[i].set_name(name);
		zombieHorde[i].announce();
	}
	return (zombieHorde);
}