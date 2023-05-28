#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
class ClapTrap
{
protected:
	std::string	_name;
	int			_hitpoints;
	int			_energypoints;
	int			_attackdamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &claptrap);
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &rhs);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string	get_name() const;
	int	get_hitpoints() const;
	int	get_engerypoints() const;
	int	get_atackdamage() const;
};
#endif