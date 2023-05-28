#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
#include <iostream>

class HumanB
{
private:
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB(std::string const &name);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon &weapon);
};
#endif