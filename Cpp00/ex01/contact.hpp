#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>

class Contact
{
private:
	static int	_next_id;
	int			_id;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;

public:
	Contact(std::string _first_name, std::string _last_name, std::string _nickname,
		std::string _phone_number, std::string _darkest_secret);
	Contact(void);
	~Contact(void);
	int			get_id(void) const;
	std::string	get_first_name(void) const;
	std::string	get_last_name(void) const;
	std::string	get_nickname(void) const;
	std::string	get_phone_number(void) const;
	std::string	get_darkest_secret(void) const;
	void		print_attributes_short(void) const;
};

#endif
