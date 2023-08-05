#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat mathieu("Mathieu", 150);
	std::cout << mathieu << std::endl;
	
	Bureaucrat anonym;
	std::cout << anonym << std::endl;

	Bureaucrat cyril("Cyril", 1);
	std::cout << cyril << std::endl;

	Bureaucrat copy(cyril);
	std::cout << "Copy say " << copy << std::endl;

	copy = mathieu;
	std::cout << "Now, the copy says he is " << copy << std::endl;

	try
	{
		cyril.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		mathieu.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat test("test", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Bureaucrat test1("test1", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "DESTRUCTION" << std::endl;

    return 0;
}