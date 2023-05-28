#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 1);
		std::cout << bob << std::endl;
		bob.decrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
/* 		 bob.incrementGrade();
		 std::cout << bob << std::endl; */

		Bureaucrat tom("Tom", 150);
		std::cout << tom << std::endl;
		tom.decrementGrade();
		std::cout << tom << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "An exception was caused" << std::endl;
	}

}