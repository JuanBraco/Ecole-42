#include "Array.hpp"

int main( void ) {
	int * a = new int();
	std::cout << *a << std::endl;
	delete a;
	
    Array<int> int_array2(0);
    Array<int> int_array3;
	Array<int> int_array(10);
    Array<std::string> string_array(10);

	for (int i = 0; i < 10; i++)
    {
        int_array[i] = i;
        string_array[i] = "Hello world";
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << int_array[i] << std::endl;
        std::cout << string_array[i] << std::endl;
    }
    std::cout << "size : " << int_array.size() << std::endl;
    std::cout << "size : " << string_array.size() << std::endl;

	std::cout << std::endl;
    Array<int> int_array_copy(int_array);
    for (int i = 0; i < 10; i++)
    {
        int_array[i] = 0;
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << int_array_copy[i];
    }
	std::cout << std::endl;

	std::cout << "\ntest out of index\n" << std::endl;

	std::cout << std::endl;
    try
    {
        int_array[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "[error] " << e.what() << '\n';
    }

	std::cout << "\ntest string\n" << std::endl;

	try
	{
		Array<std::string> integer(42);
		integer[39] = "Bob";
		std::cout << "size of " << integer.size() << std::endl;
		std::cout << "value of " << integer[39] << std::endl;
		Array<std::string> integer2(20);
		integer2[0] = "Patrick";
		integer = integer2;
		std::cout << "size of " << integer.size() << std::endl;
		std::cout << "value of " << integer2[0] << std::endl;
		std::cout << integer[45] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}