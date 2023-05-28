#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl << std::endl;



	Span sp_big = Span(100002);
	for (int i = 0; i < 100000; i++)
		sp_big.addNumber(i);
	std::cout << sp_big.shortestSpan() << std::endl;
	std::cout << sp_big.longestSpan() << std::endl;
	sp_big.addNumber(40);
	sp_big.addNumber(-1000000);
	try
	{
		sp_big.addNumber(-1);
	}
	catch (std::exception &e)
	{
		std::cout << "an exception was thrown"<< std::endl;
	}
	std::cout << sp_big.shortestSpan() << std::endl;
	std::cout << sp_big.longestSpan() << std::endl << std::endl << std::endl;


	Span sp_small(100);
	try
	{
		std::cout << sp_small.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "an exception was thrown"<< std::endl;
	}
	sp_small.addNumber(1);
	try
	{
		std::cout << sp_small.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "an exception was thrown"<< std::endl;
	}
	sp_small.addNumber(5);
	std::cout << sp_small.longestSpan() << std::endl;
	std::cout << sp_small.shortestSpan() << std::endl;

	std::multiset<int> arr;
	for (int i = 0; i < 80; i++)
	{
		arr.insert(i);
	}
	sp_small.addRange(arr.begin(), arr.end());
	std::cout << sp_small.longestSpan() << std::endl;
	std::cout << sp_small.shortestSpan() << std::endl;
	return 0;
}