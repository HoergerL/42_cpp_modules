#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool	_is_signed;
	const int _grade_sign;
	const int _grade_execute;
	Form();

public:
	Form(std::string name, int grade_sign, int grade_execute);
	Form(const Form &form);
	~Form();
	Form	&operator=(const Form &form);
	std::string	getName() const;
	bool	get_is_signed() const;
	int 	get_grade_sign() const;
	int		get_grade_execute() const;
	void	set_is_signed(bool is_signed);
	void	beSigned(Bureaucrat bureaucrat);

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

std::ostream &operator<<(std::ostream &o, const Form  &form);
#endif