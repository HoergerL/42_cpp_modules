#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat tom("Tom", 90);
		Intern *intern = new Intern();
		AForm *home = intern->makeForm("test", "home");
		AForm *presidential = intern->makeForm("PresidentialPardonForm", "target");
		std::cout << home << std::endl;
		std::cout << *presidential << std::endl;
		PresidentialPardonForm form1("PresidentialPardonForm");
		RobotomyRequestForm robot("RobotomyRequestForm");
		ShrubberyCreationForm shrubbery("ShrubberyCreationForm");
		std::cout << form1 << std::endl;
		std::cout << robot << std::endl;
		std::cout << robot << std::endl;
		//form1.beSigned(bob);
		robot.beSigned(bob);
		presidential->beSigned(bob);
		shrubbery.beSigned(bob);
		//std::cout << form1 << std::endl;
		std::cout << robot << std::endl;
		form1.execute(bob);
		bob.signForm(form1);
		std::cout << form1 << std::endl;
		bob.executeForm(form1);
		robot.execute(bob);
		bob.executeForm(shrubbery);
		bob.executeForm(*presidential);
		//tom.executeForm(form1);
		delete presidential;
		

	}
	catch (std::exception &e)
	{
		std::cout << "An exception was caused" << std::endl;
	}

}