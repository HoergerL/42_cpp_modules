#include "conversion.hpp"

void	print_nan()
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "nanf" << std::endl;
	std::cout << "double: " << "nan" << std::endl;
	exit(0);
}

void	print_inf()
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "inff" << std::endl;
	std::cout << "double: " << "inf" << std::endl;
	exit(0);
}

void	print_neg_inf()
{
	std::cout << "char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "-inff" << std::endl;
	std::cout << "double: " << "-inf" << std::endl;
	exit(0);
}

void	check_literals(std::string argv_str)
{
	if (argv_str.compare("nan") == 0 || argv_str.compare("nanf") == 0)
		print_nan();
	if (argv_str.compare("inf") == 0 || argv_str.compare("inff") == 0 || argv_str.compare("+inff") == 0 || argv_str.compare("+inf") == 0)
		print_inf();
	if (argv_str.compare("-inf") == 0 || argv_str.compare("-inff") == 0)
		print_neg_inf();
}