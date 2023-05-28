#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		Bureaucrat tom("Tom", 90);
		Form form1("form1", 70, 80);
		Form form2("form2", 70, 80);

		std::cout << bob << std::endl;
		std::cout << form1 << std::endl;
		form1.beSigned(bob);
		std::cout << form1 << std::endl;
		bob.signForm(form2);
		std::cout << form2 << std::endl;
		tom.signForm(form2);
		bob.signForm(form2);
		//form1.beSigned(tom);
	}
	catch (std::exception &e)
	{
		std::cout << "An exception was caused" << std::endl;
	}

}