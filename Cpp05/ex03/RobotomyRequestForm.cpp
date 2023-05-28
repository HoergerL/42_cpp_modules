#include "RobotomyRequestForm.hpp"
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "noone";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45),  _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = form;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	this->_target = form.getTarget();
	this->set_is_signed(form.get_is_signed());
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade()  > this->get_grade_sign())
		throw GradeTooLowException();
	if (this->get_is_signed() == true)
	{
		std::cout << "You hear some drilling noise" << std::endl;
		int random = rand() % 2;
		if (random == 1)
			std::cout << "Robotomising " << this->_target << " has failed" << std::endl;
		else
			std::cout << "Robotomising " << this->_target << " worked" << std::endl;
	}
	else
		std::cout << "The form can't be executed, it wasn't signed yet" << std::endl;
}