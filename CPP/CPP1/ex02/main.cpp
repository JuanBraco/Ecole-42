#include <limits>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "adress of the string :" << &str << std::endl;
	std::cout << "the pointer :" << ptr << std::endl;
	std::cout << "the reference :" << &ref << std::endl;
    
	std::cout << "the value of the string :" << str << std::endl;
	std::cout << "the value pointed :" << *ptr << std::endl;
	std::cout << "the value referenced :" << ref << std::endl;

	return(0);
}