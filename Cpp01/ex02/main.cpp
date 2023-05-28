#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringRef = brain;

	std::cout << "Address with var: " << &brain << std::endl;
	std::cout << "Address with pointer: " << stringPTR << std::endl;
	std::cout << "Adress with reference: " << &stringRef << std::endl;

	std::cout << "Content with pointer: " << *stringPTR << std::endl;
	std::cout << "Content with reference: " << stringRef << std::endl;
}