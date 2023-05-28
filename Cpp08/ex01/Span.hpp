#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <set>

class Span
{

private:
	std::multiset<int> _set;
	unsigned int max_size;
	Span();
public:
	Span(unsigned int N);
	Span(const Span &span);
	~Span();
	Span &operator=(const Span &span);
	void			addNumber(int number);
	unsigned int	shortestSpan();
	unsigned int	longestSpan();
	void	addRange(std::multiset<int>::iterator begin, std::multiset<int>::iterator end);
	class SetFullException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class NotEnoughElementsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
#endif