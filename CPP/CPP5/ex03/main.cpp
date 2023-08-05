#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	/*try
	{
		Bureaucrat mathieu("Mathieu", 100);
		ShrubberyCreationForm Sform("tree");
		RobotomyRequestForm Rform("Marie");
		PresidentialPardonForm Pform("Juan");
		Sform.beSigned(mathieu);
		//Rform.beSigned(mathieu);
		//Pform.beSigned(mathieu);
		std::cout << Sform << std::endl;
		std::cout << Rform << std::endl;
		std::cout << Pform << std::endl;
		Sform.execute(mathieu);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Marie("Marie", 45);
		ShrubberyCreationForm Sform("tree");
		RobotomyRequestForm Rform("Pierre");
		PresidentialPardonForm Pform("Hugo");
		//Sform.beSigned(Marie);
		Rform.beSigned(Marie);
		//Pform.beSigned(Marie);
		std::cout << Sform << std::endl;
		std::cout << Rform << std::endl;
		std::cout << Pform << std::endl;
		Marie.executeForm(Rform);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat Juan("Juan", 1);
		ShrubberyCreationForm Sform("tree");
		RobotomyRequestForm Rform("Pierre");
		Intern Charlotte;
		Form *Pform = Charlotte.makeForm("presidential pardon", "Hugo");
		//Sform.beSigned(Juan);
		//Rform.beSigned(Juan);
		Pform->beSigned(Juan);
		std::cout << Sform << std::endl;
		std::cout << Rform << std::endl;
		std::cout << *Pform << std::endl;
		Juan.executeForm(*Pform);
		Pform->execute(Juan);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}*/

	try
	{
		Bureaucrat Juan("Juan", 1);
		ShrubberyCreationForm Sform("tree");
		RobotomyRequestForm Rform("Pierre");
		Intern Charlotte;
		Form *Pform = Charlotte.makeForm("new form", "Hugo");
		//Sform.beSigned(Juan);
		//Rform.beSigned(Juan);
		Pform->beSigned(Juan);
		std::cout << Sform << std::endl;
		std::cout << Rform << std::endl;
		std::cout << *Pform << std::endl;
		Juan.executeForm(*Pform);
		Pform->execute(Juan);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}