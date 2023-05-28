#include "Form.hpp"

Form::Form() : _name("noname"), _is_signed(false), _grade_sign(1), _grade_execute(1)
{

}
Form::Form(std::string name, int grade_sign, int grade_execute)
	: _name(name), _is_signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute)
{
	if (this->_grade_sign < 0 || this->_grade_execute < 0)
		throw GradeTooHighException();
	else if (this->_grade_sign > 150 || this->_grade_execute > 150)
		throw GradeTooLowException();
}
Form::Form(const Form &form) 
	: _name(form.getName()), _is_signed(false), _grade_sign(form.get_grade_sign())
		, _grade_execute(form.get_grade_execute())
{

}

Form::~Form()
{
	
}

Form	&Form::operator=(const Form &form)
{
	this->_is_signed = form.get_is_signed();
	return (*this);
}

std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::get_is_signed() const
{
	return (this->_is_signed);
}

int 	Form::get_grade_sign() const
{
	return (this->_grade_sign);
}

int		Form::get_grade_execute() const
{
	return (this->_grade_execute);
}

void		Form::set_is_signed(bool is_signed)
{
	this->_is_signed = is_signed;
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	int grade = bureaucrat.getGrade();
	if (grade <= this->_grade_sign)
		this->_is_signed = true;
	else
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The Grade is too high, max: 1");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The Grade is too low, min: 150");
}

std::ostream &operator<<(std::ostream &o, const Form  &form)
{
	o << "Form name: " << form.getName() << ", was signed: " << form.get_is_signed();
	o << ", grades (sign, execute): " << form.get_grade_sign() << ", " << form.get_grade_execute();
	return (o);
}