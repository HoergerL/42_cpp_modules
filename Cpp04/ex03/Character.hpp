#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"


class Character : public ICharacter
{
private:
	AMateria *_slots[4];
	AMateria	*_dump[1000];
	int			dump_place;
	std::string _name;

public:
	Character();
	Character(std::string name);
	virtual ~Character();
	Character(const Character &character);
	Character &operator=(const Character &character);
	std::string const & getName() const;
	void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
};

#endif