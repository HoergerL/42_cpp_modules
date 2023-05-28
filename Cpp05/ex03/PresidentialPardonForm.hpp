#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;
	PresidentialPardonForm();

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &form);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
	std::string getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};
#endif