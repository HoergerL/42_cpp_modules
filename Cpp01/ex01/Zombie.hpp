#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(std::string name);
	Zombie(void);
	~Zombie(void);
	void	announce(void) const;
	void	set_name(std::string name);
};
#endif