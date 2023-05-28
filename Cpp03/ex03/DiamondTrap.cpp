#include "DiamondTrap.hpp"
	
DiamondTrap::DiamondTrap()
{
	this->name = "noname";
	FragTrap::_hitpoints = 100;
	ScavTrap::_energypoints = 50;
	FragTrap::_attackdamage = 30;
	ClapTrap::_name = this->name + "_clap_name";
	std::cout << "DiamondTrap default constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name)
{
	this->name = name;
	FragTrap::_hitpoints = 100;
	ScavTrap::_energypoints = 50;
	FragTrap::_attackdamage = 30;
	ClapTrap::_name = this->name + "_clap_name";
	std::cout << "DiamondTrap constructor was called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &DiamondTrap)
{
	name = DiamondTrap.get_name();
	_hitpoints = DiamondTrap.get_hitpoints();
	_energypoints = DiamondTrap.get_engerypoints();
	_attackdamage = DiamondTrap.get_atackdamage();
	ClapTrap::_name = this->name + "_clap_name";
	std::cout << "DiamondTrap copy constructor was called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor was called" << std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->name = rhs.get_name();
	this->_hitpoints = rhs.get_hitpoints();
	this->_energypoints = rhs.get_engerypoints();
	this->_attackdamage = rhs.get_atackdamage();
	return (*this);
}

void DiamondTrap::attack(std::string const & target)
{
	if (this->_energypoints != 0 && this->_hitpoints != 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
			<< this->_attackdamage << " points of damage." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
	{
		std::cout << "No Hitpoints or Energy left" << std::endl;
	}
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	std::cout << "DiamondTrap " << this->name << " took " << amount << " damage. His hit points are now: ";
	if (amount > (unsigned int) this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << this->_hitpoints << "." << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints != 0)
	{
		this->_hitpoints += amount;
		std::cout << "DiamondTrap " << this->name << " was repaired. He now has " << this->_hitpoints << " hitpoints left." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
		std::cout << "no enegerypoints left to get repaired" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "I am name: " << this->name << std::endl;
	std::cout << "I am ClapTrapName: " << ClapTrap::_name << std::endl;
}
