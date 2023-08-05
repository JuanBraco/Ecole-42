#include "Form.hpp"

Form::Form() : _name("Default"),_gradeToSign(150), _gradeToExec(150),  status(false)
{
	std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(std::string name, unsigned int gradeToSign, unsigned int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), status(false)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
			throw Form::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
			throw Form::GradeTooLowException();
}

Form::Form(Form const &rhs) : _name(rhs.getName()), _gradeToSign(rhs.getGradeToSign()), _gradeToExec(rhs.getGradeToExec()), status(false)
{
	*this = rhs;
}

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

Form &Form::operator=(Form const &obj)
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	this->status = obj.status;
	return *this;
}

const std::string Form::getName() const
{
	return this->_name;
}

unsigned int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

unsigned int Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

unsigned int Form::getStatus() const
{
	return this->status;
}

const char * Form::GradeTooHighException::what(void) const throw()
{
	return "Grade too high";
}

void	Form::beSigned(Bureaucrat const &obj)
{
		if (this->_gradeToSign >= obj.getGrade())
			this->status = true;
		else
			throw Form::GradeTooLowException();
}

const char * Form::GradeTooLowException::what(void) const throw()
{
		return "Grade too low";
}

const char * Form::FormNotSignedException::what(void) const throw()
{
	return "The Form is not signed, it cannot be executed";
}

std::ostream& operator <<(std::ostream &out, const Form &form)
{
	if (form.getStatus() == true)
	{
		out << "The form name is : " << form.getName() << \
		". It requires an grade of " << form.getGradeToSign() << " to sign it and a grade of " << \
		form.getGradeToExec() << " to execute it\nCurrently, the form is signed" << std::endl;
	}
	else
	{
		out << "The form name is : " << form.getName() << \
		". It requires an grade of " << form.getGradeToSign() << " to sign it and a grade of " << \
		form.getGradeToExec() << " to execute it\nCurrently, the form is unsigned" << std::endl;
	}

	return (out);
}