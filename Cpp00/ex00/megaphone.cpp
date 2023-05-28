#include <iostream>

std::string	str_to_upper(std::string s)
{
	std::string	res;
	int			i;

	i = 0;
	res = "";
	while (s[i] != '\0')
	{
		if (std::isalpha(s[i]))
			res += toupper(s[i]);
		else
			res += s[i];
		i++;
	}
	return res;
}

int main(int argc, char *argv[])
{
	int i;
	std::string res;

	i = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * " << std::endl;
		return (0);
	}
	while (i < argc)
	{
		res = str_to_upper(argv[i]);
		std::cout << res;
		i++;
	}
	std::cout << std::endl;
	return (0);
}