#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &intern);
	~Intern();
	Intern &operator=(const Intern &intern);
	AForm *makeForm(std::string name, std::string target);
	AForm *makePresidential(std::string name);
	AForm *makeRobot(std::string name);
	AForm *makeShrubbery(std::string name);
};

#endif