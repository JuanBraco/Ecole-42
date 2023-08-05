#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
		std::cout << "Invalid Number of arguments" << std::endl;
	else
	{
		try
		{
			RPN rpn;
			rpn.processInput(argv[1]);
			if (rpn.getNUmbers().size() == 1)
				std::cout << "The result: " << rpn.getNUmbers().front() << std::endl;
			else
				std::cout << "Error" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
		
	}
}