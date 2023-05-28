#include "contact.hpp"

Contact::Contact(std::string first_name, std::string last_name, std::string nickname,
		std::string phone_number, std::string darkest_secret) :
			_first_name(first_name), _last_name(last_name), _nickname(nickname),
			_phone_number(phone_number), _darkest_secret(darkest_secret)
{
	this->_id = _next_id;
	Contact::_next_id++;
}

Contact::Contact(void)
{
	this->_id = -1;
	this->_first_name = "";
	this->_last_name = "";
	this->_nickname = "";
	this->_phone_number = "";
	this->_darkest_secret="";
}
Contact::~Contact(void)
{
}

int	Contact::get_id(void) const
{
	return (this->_id);
}

std::string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}
std::string	truncate_to_ten(std::string s)
{
	std::string new_str;

	if (s.length() > 10)
	{
		new_str = s.substr(0, 9) + ".";
		return (new_str);
	}
	else
		return (s);
}

void Contact::print_attributes_short(void) const
{
	std::cout << std::setw(10);
	std::cout << get_id();
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate_to_ten(get_first_name());
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate_to_ten(get_last_name());
	std::cout << "|";

	std::cout << std::setw(10);
	std::cout << truncate_to_ten(get_nickname());
	std::cout << "|";

	std::cout << std::endl;
}

int Contact::_next_id = 0;