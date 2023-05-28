#include "ClapTrap.hpp"
	
ClapTrap::ClapTrap()
{
	this->_name = "noname";
	this->_hitpoints = 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	std::cout << "claptrap default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->_hitpoints = 10;
	this->_energypoints = 10;
	this->_attackdamage = 0;
	std::cout << "clap trap constructor was called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap) : 
	_name(claptrap.get_name()), _hitpoints(claptrap.get_hitpoints()), _energypoints(claptrap.get_engerypoints()),
	_attackdamage(claptrap.get_atackdamage())
{
	std::cout << "claptrap copy constructor was called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "claptrap destructor was called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs.get_name();
	this->_hitpoints = rhs.get_hitpoints();
	this->_energypoints = rhs.get_engerypoints();
	this->_attackdamage = rhs.get_atackdamage();
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_energypoints != 0 && this->_hitpoints != 0)
	{
		std::cout << "Claptrap " << this->_name << " attacks " << target << ", causing "
			<< this->_attackdamage << " points of damage." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
	{
		std::cout << "No Hitpoints or Energy left" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "Claptrap " << this->_name << " took " << amount << " damage. His hit points are now: ";
	if (amount > (unsigned int) this->_hitpoints)
		this->_hitpoints = 0;
	else
		this->_hitpoints -= amount;
	std::cout << this->_hitpoints << "." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energypoints != 0)
	{
		this->_hitpoints += amount;
		std::cout << "Claptrap " << this->_name << " was repaired. He now has " << this->_hitpoints << " hitpoints left." << std::endl;
		this->_energypoints--;
		std::cout << "Energy left: " << this->_energypoints << std::endl;
	}
	else
		std::cout << "no enegerypoints left to get repaired" << std::endl;
}

std::string	ClapTrap::get_name() const
{
	return (this->_name);
}

int	ClapTrap::get_hitpoints() const
{
	return (this->_hitpoints);
}

int	ClapTrap::get_engerypoints() const
{
	return(this->_energypoints);
}

int	ClapTrap::get_atackdamage() const
{
	return(this->_attackdamage);
}