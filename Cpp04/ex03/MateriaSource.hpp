#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{

private:
	AMateria	*_slots[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &source);
	MateriaSource	&operator=(const MateriaSource &source);
	virtual void learnMateria(AMateria*materia);
	virtual AMateria* createMateria(std::string const & type);
};
#endif