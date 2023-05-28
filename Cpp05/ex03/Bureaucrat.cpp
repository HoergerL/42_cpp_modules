#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :_name("noname"), _grade(1)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat::~Bureaucrat()
{

}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}
void		Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}
void		Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void		Bureaucrat::signForm(AForm &form)
{
	if (form.get_grade_sign() < this->_grade)
	{
		std::cout << this->_name << "couldn't sign " << form.getName();
		std::cout << " because his grade isn't high enough"<< std::endl;
	}
	else if (form.get_is_signed() == false)
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.set_is_signed(true);
	}
	else
	{
		std::cout << this->_name << "couldn't sign " << form.getName();
		std::cout << "because it was already signed" << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const &form)
{
	bool was_executed = true;
	try
	{
		form.execute(*this);
	}
	catch(std::exception e)
	{
		was_executed = false;
	}
	if (was_executed == true)
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The Grade is too high, max: 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The Grade is too low, min: 150");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat  &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (o);
}