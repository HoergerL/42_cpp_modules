#ifndef AMATERIA_H
#define AMATERIA_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const & type);
	AMateria();
	AMateria(const AMateria &materia);
	virtual ~AMateria();
	std::string const & getType() const;
	AMateria &operator=(const AMateria &materia);
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif