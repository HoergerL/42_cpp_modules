#include "Karen.hpp"
#include <iostream>

Karen::Karen(void)
{

}

Karen::~Karen(void)
{

}

void	Karen::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple";
	std::cout << "-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. You ";
	std::cout << "don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been";
	std::cout << "coming here for years and you just started working here ";
	std::cout << "last month." << std::endl;
}

void	Karen::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	int i = 0;
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Karen::*f[]) (void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};

	while (i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0: (this->*f[0])();
		case 1: (this->*f[1])();
		case 2: (this->*f[2])();
		case 3: (this->*f[3])(); break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}