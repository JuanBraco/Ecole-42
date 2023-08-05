#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(Intern const &rhs)
{
	*this = rhs;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &obj)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	(void)obj;
	return *this;
}



const char * Intern::FormInexistantException::what(void) const throw()
{
	return "The form doesn't exist";
}

Form*	Intern::makeForm(const std::string formName, const std::string target)
{
		const std::string	forms[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
		int i = 0;

		while(i < 3 && (forms[i].compare(formName)))
			i++;
		switch (i)
		{
			case 0 :
				std::cout << "Intern creates a " << forms[0] << " form." << std::endl;
				return (new ShrubberyCreationForm(target));
			case 1 :
				std::cout << "Intern creates a " << forms[1] << " form." << std::endl;
				return (new RobotomyRequestForm(target));
			case 2 :
				std::cout << "Intern creates a " << forms[1] << " form." << std::endl;
				return (new PresidentialPardonForm(target));
			default :
				throw (Intern::FormInexistantException());
		}
}
