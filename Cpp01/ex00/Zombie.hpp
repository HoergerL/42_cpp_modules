#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie
{
private:
	std::string  const _name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void) const;
};
#endif