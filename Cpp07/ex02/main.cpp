#include "Array.hpp"

int main()
{
	Array<char> arr_empty;
	std::cout << arr_empty.size() << std::endl;
	try
	{
		std::cout << arr_empty[3] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "An error occured" << std::endl;
	}


	Array<int> arr(5);
	arr[3] = 6;
	std::cout << arr[3] << std::endl;
	std::cout << arr[4] << std::endl;
	std::cout << arr.size() << std::endl;


	Array<int> arr_ints;
	arr_ints = arr;
	std::cout << &arr_ints[3] << std::endl;
	std::cout << &arr[3] << std::endl;
	
}