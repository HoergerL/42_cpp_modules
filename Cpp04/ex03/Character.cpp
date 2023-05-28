#include "Character.hpp"

Character::Character()
{
	dump_place = 0;
}

Character::Character(std::string name) : _slots(), _dump(), dump_place(0), _name(name)
{

}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_slots[i];
	for (int i = 0; i < this->dump_place; i++)
		delete this->_dump[i];
}
	
Character::Character(const Character &character)
{
	*this = character;
}

Character &Character::operator=(const Character &character)
{
	int j;

	j = 0;
	for (int i = 0; i < 4; i++)
		delete this->_slots[i];
	for (int i = 0; i < 4; i++)
		this->_slots[i] = character._slots[i]->clone();
	for (int i = 0; i < dump_place; i++)
		delete this->_dump[i];
	dump_place = character.dump_place;
	this->_name = character.getName();
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == 0)
	{
		std::cout << "this Materia can't be equipped" << std::endl;
		return ;
	}
	if (this->dump_place == 999)
	{
		std::cout << "the memory of this program is full" << std::endl;
		delete m;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			std::cout << "Materia was equipped at slot " << i << std::endl;
			return ;
		}
	}
	std::cout << "All slots are full" << std::endl;
	this->_dump[this->dump_place] = m;
	this->dump_place++;
}

void Character::unequip(int idx)
{
	if (idx < 4 && idx > 0 && this->_slots[idx] != 0)
	{
		this->_dump[this->dump_place] = this->_slots[idx];
		this->dump_place++;
		this->_slots[idx] = NULL;
		std::cout << "unequiped slot " << idx << std::endl;
	}
	else
	std::cout << "couldn't unequip this slot" << std::endl;
}
void Character::use(int idx, ICharacter& target)
{
	if (this->_slots[idx] != 0)
		this->_slots[idx]->use(target);
	else
		std::cout << "there is nothing equiped at slot " << idx << std::endl;
}