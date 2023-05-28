#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
}

Ice::Ice(std::string const & type)
{
	this->_type = type;
}

Ice::Ice (const Ice &ice)
{
	*this = ice;
}

Ice::~Ice()
{

}

Ice &Ice::operator=(const Ice &ice)
{
	this->_type = ice._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	std::cout << "clone was created" << std::endl;
	return (new Ice(this->_type));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}