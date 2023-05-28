#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
}

Cure::Cure(std::string const & type)
{
	this->_type = type;
}

Cure::Cure (const Cure &cure)
{
	*this = cure;
}

Cure::~Cure()
{

}

Cure &Cure::operator=(const Cure &cure)
{
	this->_type = cure._type;
	return (*this);
}

AMateria* Cure::clone() const
{
	std::cout << "clone was created" << std::endl;
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}