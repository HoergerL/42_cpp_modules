#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern &intern)
{
	(void) intern;
}

Intern::~Intern()
{

}

Intern &Intern::operator=(const Intern &intern)
{
	(void) intern;
	return (*this);
}

AForm *Intern::makePresidential(std::string name)
{
	std::cout << "Intern creates PresidentialForm" << std::endl;
	return (new PresidentialPardonForm(name));
}

AForm *Intern::makeRobot(std::string name)
{
	std::cout << "Intern creates RobotForm" << std::endl;
	return (new RobotomyRequestForm(name));
}

AForm *Intern::makeShrubbery(std::string name)
{
	std::cout << "Intern creates ShrubberyForm" << std::endl;
	return (new ShrubberyCreationForm(name));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm" };

	AForm *(Intern::*f[])(std::string name) = { &Intern::makePresidential, &Intern::makeRobot, &Intern::makeShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == name)
			return ((this->*f[i])(target));
	}
	std::cout << name << ": This form does not exist" << std::endl;
	return (NULL);
}