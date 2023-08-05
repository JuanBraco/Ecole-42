#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(),  _target("Default")
{
	std::cout << "Form Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137),  _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : Form(rhs)
{
	*this = rhs;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &obj)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(!this->getStatus())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExec())
        throw Form::GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    file << "tree";
}