#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form(),  _target("Default")
{
	std::cout << "Form Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5),  _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : Form(rhs)
{
	*this = rhs;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

const std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(!this->getStatus())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExec())
        throw Form::GradeTooLowException();
    std::cout << _target<< " has been forgiven by Zaphod Beeblerox" << std::endl;
}