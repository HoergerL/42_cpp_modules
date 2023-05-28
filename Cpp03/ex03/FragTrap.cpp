#include "FragTrap.hpp"
	
FragTrap::FragTrap()
{
	this->name = "noname";
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout << "FragTrap default constructor was called" << std::endl;
}

FragTrap::FragTrap(std::string name) : 	ClapTrap(name)
{
	this->name = name;
	this->_hitpoints = 100;
	this->_energypoints = 100;
	this->_attackdamage = 30;
	std::cout << "FragTrap constructor was called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &FragTrap)
{
	name = FragTrap.get_name();
	_name = name;
	_hitpoints = FragTrap.get_hitpoints();
	_energypoints = FragTrap.get_engerypoints();
	_attackdamage = FragTrap.get_atackdamage();
	std::cout << "FragTrap copy constructor was called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor was called" << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &rhs)
{
	this->name = rhs.get_name();
	this->_hitpoints = rhs.get_hitpoints();
	this->_energypoints = rhs.get_engerypoints();
	this->_attackdamage = rhs.get_atackdamage();
	return (*this);
}
void FragTrap::attack(std::string const & target)
{
	if (this->_energypoints != 0 && this->_hitpoints != 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target << ", causing "
			<< this->_attackdamage << " points of damage." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
	{
		std::cout << "No Hitpoints or Energy left" << std::endl;
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->name << " took " << amount << " damage. His hit points are now: ";
	if (amount > (unsigned int) this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << this->_hitpoints << "." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints != 0)
	{
		this->_hitpoints += amount;
		std::cout << "FragTrap " << this->name << " was repaired. He now has " << this->_hitpoints << " hitpoints left." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
		std::cout << "no enegerypoints left to get repaired" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " wants a high five" << std::endl;
}