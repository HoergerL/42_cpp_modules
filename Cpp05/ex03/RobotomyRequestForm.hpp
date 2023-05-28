#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &form);
	~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
	std::string getTarget() const;
	void	execute(Bureaucrat const & executor) const;
};
#endif