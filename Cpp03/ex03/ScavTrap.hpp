#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	std::string name;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ScavTrap);
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &rhs);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void guardGate();
};

#endif