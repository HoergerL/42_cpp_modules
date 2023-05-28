#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{

public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	MutantStack() : std::stack<T>(){}
	~MutantStack() {};
	MutantStack(const MutantStack &stack) : std::stack<T>(stack){};
	MutantStack operator=(const MutantStack &stack)
	{
		*this = stack;
		return (*this);
	}
	bool	empty() const
	{
		return (std::stack<T>::empty());
	}

	size_t	size() const
	{
		return (std::stack<T>::size());
	}

	T	&top()
	{
		return (std::stack<T>::top());
	}

	const T &top() const
	{
		return (std::stack<T>::top());
	}

	void	push(const T &val)
	{
		std::stack<T>::push(val);
	}

	void	pop()
	{
		std::stack<T>::pop();
	}
	iterator begin()
	{
		return (this->c.begin());
	}

	const_iterator begin() const
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}

	const_iterator end() const
	{
		return (this->c.end());
	}
	reverse_iterator rbegin()
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator rbegin() const
	{
		return (this->c.rbegin());
	}

	reverse_iterator rend()
	{
		return (this->c.rend());
	}

	const_reverse_iterator rend() const
	{
		return(this->c.rend());
	}

};
#endif