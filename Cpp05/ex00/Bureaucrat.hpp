#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Bureaucrat
{
private:
	const std::string _name;
	int	_grade;
	Bureaucrat();

public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);
	std::string	getName() const;
	int			getGrade() const;
	void		incrementGrade();
	void		decrementGrade();

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

std::ostream &operator<<(std::ostream &o, const Bureaucrat  &bureaucrat);

#endif
