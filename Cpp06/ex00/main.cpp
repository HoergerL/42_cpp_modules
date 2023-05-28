#include "conversion.hpp"
#include <bits/stdc++.h>
#include <float.h>

int check_num(std::string argv)
{
	if (argv.find_first_not_of("0123456789-+") == std::string::npos)
		return (INT);
	if (argv.find_first_not_of("0123456789-+.") == std::string::npos)
		return (DOUBLE);
	if (argv.find_first_not_of("0123456789-+.f") == std::string::npos)
		return (FLOAT);
	else
		return (-1);
}

int check_char(std::string argv)
{
	if (argv.length() == 1)
		return (CHAR);
	else
		return (-1);
}
int check_actual_type(std::string argv)
{
	int actual_type;

	actual_type = check_num(argv);
	if (actual_type == -1)
	{
		actual_type = check_char(argv);
		if (actual_type == -1)
		{
			std::cout << "the input is none of the selected types." << std::endl;
			exit(1);
		}
	}
	return (actual_type);
}


void	print_types_int(char c, int i, float f, double d, int overflow[4])
{
	if (isprint(c) && overflow[CHAR] != 1)
		std::cout << "char: " << c << std::endl;
	else
	{
		if (overflow[CHAR] == 1)
			std::cout << "char: " << "Impossible" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << ".0f" << std::endl;
	std::cout << "double: " << d << ".0" << std::endl;
}

void	print_types_double(char c, int i, float f, double d, int overflow[4])
{
	double fractpart = fmod(d, 1.0);
	if (fractpart == 0.0 && overflow[CHAR] != 1)
	{
		if (isprint(c) && fractpart == 0.0)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
	}
	else
		std::cout << "char: " << "Impossible" << std::endl;
	if (fractpart == 0.0)
	{
		if (overflow[INT] == 1)
			std::cout << "int: " << "Impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;

		std::cout << std::showpoint;
		if (overflow[FLOAT] == 1)
			std::cout << "float: " << "Impossible" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;

		if (overflow[DOUBLE] == 1)
			std::cout << "double: " << "Impossible" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	else
	{
		std::cout << "int: " << "Impossible" << std::endl;
		if (overflow[FLOAT] == 1)
			std::cout  << "float: " << "Impossible" << std::endl;
		else
		{
			//std::cout.precision(7);
			std::cout << "float: " << f << "f" << std::endl;
		}
		if (overflow[DOUBLE] == 1)
			std::cout << "double: " << "Impossible" << std::endl;
		else
		{
			//std::cout.precision(15);
			std::cout << "double: " << d << std::endl;
		}
	}
}

void	transform_int(int i, int overflow[4])
{
	if (i > CHAR_MAX || i < CHAR_MIN)
		overflow[CHAR] = 1;
	std::cout << "transform int " << std::endl;
	print_types_int(static_cast<char> (i), i, static_cast<float> (i), static_cast<double> (i), overflow);
}

void transform_double(double d, int overflow[4])
{
	if (d > static_cast<double>(FLT_MAX) || d < static_cast<double>(-FLT_MAX))
		overflow[FLOAT] = 1;
	if (d > static_cast<double>(INT_MAX) || d < static_cast<double>(-INT_MAX))
		overflow[INT] = 1;
	if (d > CHAR_MAX || d < CHAR_MIN)
		overflow[CHAR] = 1;
	std::cout << "transform double " << std::endl;
	print_types_double(static_cast<char> (d), static_cast<int> (d), static_cast<float> (d), d, overflow);
}

void transform_float(float f, int overflow[4])
{
	if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
		overflow[INT] = 1;
	if (f > CHAR_MAX || f < CHAR_MIN)
		overflow[CHAR] = 1;
	std::cout << "transform float " << std::endl;
	print_types_double(static_cast<char> (f), static_cast<int> (f), f, static_cast<double> (f), overflow);
}

void transform_char(char c, int overflow[4])
{
	std::cout << "transform char " << std::endl;
	print_types_int(c, static_cast<int> (c), static_cast<float> (c), static_cast<double> (c), overflow);
}

void execute_transformations(int actual_type, char *argv_str, int overflow[4])
{
	if (actual_type == INT)
		transform_int(atoi(argv_str), overflow);
	else if (actual_type == DOUBLE)
		transform_double(atof(argv_str), overflow);
	else if (actual_type == FLOAT)
		transform_float(strtof(argv_str, NULL), overflow);
	else
		transform_char(argv_str[0], overflow);
		
}

void	check_overflow(char *char_str, int *actual_type, int overflow[4])
{
	if (*actual_type == INT && (atol(char_str) > INT_MAX || atol(char_str) < INT_MIN))
	{
		*actual_type = DOUBLE;
		overflow[INT] = 1;
	}
	if (*actual_type == FLOAT && (strtold(char_str, NULL) > FLT_MAX || strtold(char_str, NULL) < -FLT_MAX))
	{
		*actual_type = DOUBLE;
		overflow[FLOAT] = 1;
	}
	if (*actual_type == DOUBLE && (strtold(char_str, NULL) > DBL_MAX || strtold(char_str, NULL) < -DBL_MAX))
		overflow[DOUBLE] = 1;

}

int main(int argc, char **argv)
{
	int overflow[4] = {0};
	if (argc != 2)
	{
		std::cout << "The program needs exactly one paramter" << std::endl;
		return (1);
	}
	std::string argv_str = argv[1];
	check_literals(argv_str);
	int actual_type = check_actual_type(argv_str);
	//std::cout << "actual type: " << actual_type << std::endl;
	check_overflow(argv[1], &actual_type, overflow);
	// for (int i = 0; i < 4; i++)
	// 	std::cout << overflow[i] << std::endl;
	execute_transformations(actual_type, argv[1], overflow);
	return(1);
}