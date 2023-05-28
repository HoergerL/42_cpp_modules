#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "noone";

}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5),  _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = form;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	this->_target = form.getTarget();
	this->set_is_signed(form.get_is_signed());
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade()  > this->get_grade_sign())
		throw GradeTooLowException();
	if (this->get_is_signed() == true)
		std::cout << "Zaphod Beeblebrox pardoned " << this->_target << std::endl;
	else
		std::cout << "The form can't be executed, it wasn't signed yet" << std::endl;
}