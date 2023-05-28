#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
}

AMateria::AMateria()
{
	this->_type = "noType";
}

AMateria::AMateria(const AMateria &materia)
{
	*this = materia;
}

AMateria::~AMateria()
{

}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

AMateria &AMateria::operator=(const AMateria &materia)
{
	(void) materia;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	(void) target; // raus
	std::cout << "Amaterial Function use" << std::endl;
}