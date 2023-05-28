#include "phonebook.hpp"
#include <stdlib.h>

void	print_welcome(void)
{
	std::cout << "Welcome to this crappy awesome phonebook." << std::endl;
	std::cout << "Use the following commands to navigate:" << std::endl;
	std::cout << "You can add contacts with the command ADD" << std::endl;
	std::cout << "If you want to display your contacts use SEARCH" << std::endl;
	std::cout << "To end the programm type EXIT" << std::endl;
}

std::string	get_alpha_userinput(std::string to_get)
{
	std::string user_input;
	bool is_alpha;
	int i;

	std::cout << "what's the " << to_get << " of your contact?" << std::endl;
	while (1)
	{
		user_input = "";
		std::cout << "> ";
		std::getline(std::cin, user_input);
		i = 0;
		is_alpha = true;
		while (user_input[i])
		{
			if (!isalpha(user_input[i]))
			{
				std::cout << to_get << " can only contain letters" << std::endl;
				is_alpha = false;
				break ;
			}
			i++;
		}
		if (is_alpha == true)
			break ;
	}
	return (user_input);
}

std::string get_phone_number_userinput(void)
{
	std::string phone_number;
	int i;
	std::cout << "what's the phone number of your contact?" << std::endl;
	while (1)
	{
		phone_number = "";
		std::cout << "> ";
		std::getline(std::cin, phone_number);
		i = 0;
		if (phone_number.find_first_not_of("1234567890/+ ") == std::string::npos)
			break ;
		std::cout << "A Phone number can only contain numbers, blanks, plus and slash" << std::endl;
	}
	return (phone_number);
}

void	execute_add(Phonebook *phonebook)
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	first_name = get_alpha_userinput("first name");
	last_name = get_alpha_userinput("last name");

	std::cout << "what's the nickname name of your contact?" << std::endl << "> ";
	std::getline(std::cin, nickname);

	phone_number = get_phone_number_userinput();

	std::cout << "what's the darkest secret of your contact?" << std::endl << "> ";
	std::getline(std::cin, darkest_secret);

	Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook->add_contact(contact);
}

void	execute_search(Phonebook *phonebook)
{
	std::string	input;
	int	index;

	if (phonebook->display_phonebook_short() == 1)
		return ;
	std::cout << "Which contact do you want to see closer?" << std::endl;
	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (input.find_first_not_of("1234567890") == std::string::npos)
		{
			index = phonebook->get_index_of_contact_by_id(atoi(input.c_str()));
			if (index == -1)
				std::cout << "This index does not exist" << std::endl;
			else
			{
				phonebook->display_contact(index);
				return ;
			}
		}
		else
			std::cout << "Your input was not numerical, please try again" << std::endl;
	}

}

void	print_error()
{
	std::cout << "Your input is not valid, please try again" << std::endl;
}

int		main(void)
{
	std::string input;
	Phonebook phonebook;
	print_welcome();
	while (1)
	{
		input = "";
		std::cout << ">> ";
		std::getline(std::cin, input);
		if (input == "")
			return (1);
		if (input == "ADD")
			execute_add(&phonebook);
		else if (input.compare("SEARCH") == 0)
			execute_search(&phonebook);
		else if (input.compare("EXIT") == 0)
			return (0);
		else
			print_error();
	}
}