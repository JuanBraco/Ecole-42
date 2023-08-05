#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : Form(),  _target("Default")
{
	std::cout << "Form Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45),  _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : Form(rhs)
{
	*this = rhs;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &obj)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	this->_target = obj._target;
	return *this;
}

const std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(!this->getStatus())
        throw Form::FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExec())
        throw Form::GradeTooLowException();
    std::srand(std::time(0));
    if (std::rand() % 2){
        std::cout << "bsiiiiii " << _target<< " has been robotised" << std::endl;
    }
    else {
        std::cout << "Ohhhh" << _target<< " has not been robotised - lucky" << std::endl;
    }

}