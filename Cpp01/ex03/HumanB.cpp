#include "HumanB.hpp"

HumanB::HumanB(std::string const &name) : _name(name)
{
	_weapon = NULL;
}

HumanB::~HumanB(void)
{

}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	std::cout << this->_name << " attacks with " << this->_weapon->getType() << std::endl;
}