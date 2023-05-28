#include "phonebook.hpp"

Phonebook::Phonebook(void)
{
}

Phonebook::~Phonebook(void)
{
}


void	Phonebook::add_contact(Contact new_contact)
{
	int	i;
	int	lowest_id;
	int	index_lowest_id;

	i = 0;
	lowest_id = INT_MAX;

	while (i < 8)
	{
		if (this->_contacts[i].get_id() == -1)
		{
			this->_contacts[i] = new_contact;
			return ;
		}
		if (this->_contacts[i].get_id() < lowest_id)
		{
			lowest_id = this->_contacts[i].get_id();
			index_lowest_id = i;
		}
		i++;
	}
	_contacts[index_lowest_id] = new_contact;
}

int	Phonebook::display_phonebook_short() const
{
	int	i;

	i = 0;
	if (this->_contacts[0].get_id() == -1)
	{
		std::cout << "This phonebook doesn't contain any contacts. Please add them with ADD" << std::endl;
		return (1);
	}
	std::cout << std::setw(10);
	while(i < 8)
	{
		if (this->_contacts[i].get_id() == -1)
			break ;
		this->_contacts[i].print_attributes_short();
		i++;
	}
	return (0);
}

void	Phonebook::display_contact(int index) const
{
	std::cout << "Id: " << this->_contacts[index].get_id() << std::endl;
	std::cout << "First name: " << this->_contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << this->_contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << this->_contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << this->_contacts[index].get_darkest_secret() << std::endl;
}

int	Phonebook::get_index_of_contact_by_id(int id) const
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (this->_contacts[i].get_id() == id)
			return (i);
		i++;
	}
	return (-1);
}