#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool	_is_signed;
	const int _grade_sign;
	const int _grade_execute;
	AForm();

public:
	AForm(std::string name, int grade_sign, int grade_execute);
	AForm(const AForm &form);
	virtual ~AForm();
	AForm	&operator=(const AForm &form);
	std::string	getName() const;
	bool	get_is_signed() const;
	int 	get_grade_sign() const;
	int		get_grade_execute() const;
	void	set_is_signed(bool is_signed);
	void	beSigned(Bureaucrat bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, const AForm  &form);
#endif