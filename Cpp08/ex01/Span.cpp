#include "Span.hpp"
#include <limits>
#include <algorithm>

Span::Span()
{
	this->max_size = 0;
}

Span::Span(unsigned int N)
{
	this->max_size = N;
}

Span::Span(const Span &span): _set(span._set),  max_size(span.max_size) {}

Span::~Span()
{

}

Span &Span::operator=(const Span &span)
{
	this->max_size = span.max_size;
	this->_set = span._set;
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->_set.size() < this->max_size)
		this->_set.insert(number);
 	else
		throw SetFullException();
}
unsigned int	Span::shortestSpan()
{
	if (this->_set.size() <= 1)
		throw NotEnoughElementsException();
	std::multiset<int>::const_iterator first = this->_set.begin();
	std::multiset<int>::const_iterator next = ++(this->_set.begin());
	unsigned int shortest = std::abs(*first - *next);
	while (next != this->_set.end())
	{
		if ((unsigned int) std::abs(*first - *next) < shortest)
			shortest = (unsigned int) std::abs(*first - *next);
		++first;
		++next;
	}
	return (shortest);
}

unsigned int	Span::longestSpan()
{
	if (this->_set.size() <= 1)
		throw NotEnoughElementsException();
	// int begin = *(this->_set.begin());
	// int end = *(--(this->_set.end()));
	int begin = *(std::min_element(this->_set.begin(), this->_set.end()));
	int end = *(std::max_element(this->_set.begin(), this->_set.end()));
	return (end - begin);

}

void	Span::addRange(std::multiset<int>::iterator begin, std::multiset<int>::iterator end)
{
	if ((unsigned int) std::distance(begin, end) <= this->max_size - (unsigned int) this->_set.size())
		this->_set.insert(begin, end);
	else	
		throw SetFullException();
}

const char* Span::SetFullException::what() const throw()
{
	return ("The Span is already full");
}

const char* Span::NotEnoughElementsException::what() const throw()
{
	return ("There are not enough Elements to calculate a Span");
}