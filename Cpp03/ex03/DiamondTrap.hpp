#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{

private:
	std::string	name;
public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &DiamondTrap);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &rhs);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void	whoAmI();
};

#endif