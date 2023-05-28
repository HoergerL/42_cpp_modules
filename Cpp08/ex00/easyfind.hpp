#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <vector>
#include <iostream>
#include <list>

template <typename T>
int	easyfind(T container, int to_find)
{
	typename T::iterator p = std::find(container.begin(), container.end(), to_find);
	if (p != container.end())
		return (std::distance(container.begin(), p));
	else
		return (-1);
}

#endif