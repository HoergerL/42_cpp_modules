#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <string.h>

int	error_handling(int argc, char *argv[])
{
	std::string s1;
	std::string s2;
	std::string file_name;

	if (argc != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return (1);
	}
	file_name = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (file_name == "" || s1 == "" || s2 == "")
	{
		std::cout << "One Argument is empty" << std::endl;
		return (1);
	}
	return (0);
}
int main(int argc, char *argv[])
{
	std::ifstream	inputfs;
	std::ofstream	outputfs;
	std::string		in_file_name;
	std::string		out_file_name;
	std::string		line;
	int				found_string;

	if (error_handling(argc, argv) == 1)
		return (1);
	in_file_name = argv[1];
	out_file_name = in_file_name + ".replace";
	inputfs.open(in_file_name);
	if (inputfs.fail())
	{
		std::cout << "infile can't be opened" << std::endl;
		return (1);
	}
	outputfs.open(out_file_name);
	if (outputfs.fail())
	{
		inputfs.close();
		std::cout << "oufile can't be opened" << std::endl;
		return (1);
	}
	
	while (std::getline(inputfs, line))
	{
		found_string = line.find(argv[2]);
		while (found_string != -1)
		{
			outputfs <<  line.substr(0, found_string) + argv[3];
			if (line.length() < found_string  + strlen(argv[2]))
				break;
			line = line.substr(found_string  + strlen(argv[2]));
			found_string = line.find(argv[2]);
		}
		outputfs << line << std::endl;
	}
	inputfs.close();
	outputfs.close();

}