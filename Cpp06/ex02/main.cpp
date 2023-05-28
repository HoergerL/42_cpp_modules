#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <stdint.h>
#include <bsd/stdlib.h>
#include <iostream>

Base * generate(void)
{
	int rand = arc4random() % 3;
	std::cout << rand << std::endl;
	if (rand == 0)
		return (new A());
	else if (rand == 1)
		return(new B());
	else
		return (new C());
}

void identify(Base& p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << "it was A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{

	}
	try
	{
		(void) dynamic_cast<B&>(p);
		std::cout << "it was B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{

	}
	try
	{
		(void) dynamic_cast<C&>(p);
		std::cout << "it was C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{

	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "it was A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "it was B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "it was C" << std::endl;
}

int main()
{
	Base *b = generate();
	Base &ref = *b;
	identify(b);
	identify(ref);
}