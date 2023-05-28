#include "easyfind.hpp"


int main()
{
	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(45);
	vec.push_back(53);
	vec.push_back(51);
	vec.push_back(56);
	vec.push_back(45);
	std::cout << easyfind(vec, 45) << std::endl;
	std::cout << easyfind(vec, 51) << std::endl;
	std::cout << easyfind(vec, 15) << std::endl;


	std::list<int> list;
	list.push_back(4);
	list.push_back(44);
	list.push_back(42);
	list.push_back(41);
	list.push_back(49);
	std::cout << easyfind(list, 44) << std::endl;
	std::cout << easyfind(list, 49) << std::endl;
	std::cout << easyfind(list, 94) << std::endl;
}