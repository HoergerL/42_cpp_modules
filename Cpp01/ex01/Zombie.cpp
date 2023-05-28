#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << "Zombie " << this->_name << " was created" <<std::endl;
}

Zombie::Zombie(void)
{
	this->_name = "";
	std::cout << "Zombie " << this->_name << " was created" <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->_name << " was destroyed" <<std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}