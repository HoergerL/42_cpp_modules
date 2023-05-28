#include "ScavTrap.hpp"
	
ScavTrap::ScavTrap()
{
	this->_name = "noname";
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "ScavTrap default constructor was called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 	ClapTrap(name)
{
	this->_hitpoints = 100;
	this->_energypoints = 50;
	this->_attackdamage = 20;
	std::cout << "ScavTrap constructor was called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &ScavTrap)
{
	_name = ScavTrap.get_name();
	_hitpoints = ScavTrap.get_hitpoints();
	_energypoints = ScavTrap.get_engerypoints();
	_attackdamage = ScavTrap.get_atackdamage();
	std::cout << "ScavTrap copy constructor was called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor was called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs.get_name();
	this->_hitpoints = rhs.get_hitpoints();
	this->_energypoints = rhs.get_engerypoints();
	this->_attackdamage = rhs.get_atackdamage();
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (this->_energypoints != 0 && this->_hitpoints != 0)
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackdamage << " points of damage." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
	{
		std::cout << "No Hitpoints or Energy left" << std::endl;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->_name << " took " << amount << " damage. His hit points are now: ";
	if (amount > (unsigned int) this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << this->_hitpoints << "." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints != 0)
	{
		this->_hitpoints += amount;
		std::cout << "ScavTrap " << this->_name << " was repaired. He now has " << this->_hitpoints << " hitpoints left." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
		std::cout << "no enegerypoints left to get repaired" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " entered the gate keeper mode" << std::endl;
}