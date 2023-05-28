#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <list>
# include <iostream>
# include "contact.hpp"
# include "limits.h"
# include <iomanip>

class Phonebook
{
private:
	Contact _contacts[8];

public:
	Phonebook(void);
	~Phonebook(void);
	void	add_contact(Contact contact);
	int		display_phonebook_short(void) const;
	void	display_contact(int index) const;
	int		get_index_of_contact_by_id(int id) const;
};
#endif