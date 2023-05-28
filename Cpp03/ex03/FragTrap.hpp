#ifndef FragTrap_HPP
#define FragTrap_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	std::string name;
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &FragTrap);
	~FragTrap();
	FragTrap &operator=(const FragTrap &rhs);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void highFivesGuys(void);
};

#endif