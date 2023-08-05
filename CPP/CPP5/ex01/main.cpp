#include "Bureaucrat.hpp"

int main()
{

	try
	{
		Bureaucrat mathieu("Mathieu", 20);
		Form form42("form42", 42, 150);
		form42.beSigned(mathieu);
		std::cout << form42 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat pierre("pierre", 120);
		Form form100("form100", 100, 150);
		form100.beSigned(pierre);
		std::cout << form100 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}