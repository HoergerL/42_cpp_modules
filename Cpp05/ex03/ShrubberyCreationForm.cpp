#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "noone";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),  _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = form;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	this->_target = form.getTarget();
	this->set_is_signed(form.get_is_signed());
	return (*this); // nochmal prüfen
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade()  > this->get_grade_sign())
		throw GradeTooLowException();
	if (this->get_is_signed() == true)
	{
		drawTree();
	}
	else
		std::cout << "The form can't be executed, it wasn't signed yet" << std::endl;
}

void ShrubberyCreationForm::drawTree() const
{
	std::string tmp = this->getTarget() + "_shrubbery";
	std::ofstream ofs(tmp.c_str());
	ofs << "               ,@@@@@@@,\n";
	ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	ofs << "       |o|        | |         | |\n";
	ofs << "       |.|        | |         | |\n";
	ofs << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ for " + this->getTarget() + "\n";
	ofs.close();
}