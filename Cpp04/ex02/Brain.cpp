#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Counstructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain Copy Counstructor" << std::endl;
	*this = brain;
}

Brain	&Brain::operator=(const Brain &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

std::string* Brain::getIdeas()
{
	return (this->ideas);
}