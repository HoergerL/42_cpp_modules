#include "ScavTrap.hpp"

int main()
{
	ScavTrap scavi("scavi");
	scavi.attack("bad people");
	scavi.takeDamage(3);
	scavi.beRepaired(20);
	scavi.guardGate();
}