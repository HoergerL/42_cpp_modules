#include "Zombie.hpp"

Zombie* newZombie( std::string name);
void randomChump( std::string name );
int main()
{
	Zombie *scapegrace = newZombie("Scapegrace");
	randomChump("Thrasher");
	scapegrace->announce();
	delete scapegrace;
	return (0);
}