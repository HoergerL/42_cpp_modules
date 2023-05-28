#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _slots()
{

}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_slots[i];
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	*this = source;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_slots[i];
		this->_slots[i] = source._slots[i];
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] == 0)
		{
			this->_slots[i] = materia;
			std::cout << "Materia was stored" << std::endl;
			return ;
		}
	}
	delete materia;
	std::cout << "Materia All slots are full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_slots[i] != 0 && type == this->_slots[i]->getType())
		{
			std::cout << "Materia was created" << std::endl;
			return (this->_slots[i]->clone());
		}
	}
	std::cout << "no Materia found" << std::endl;
	return (NULL);
}