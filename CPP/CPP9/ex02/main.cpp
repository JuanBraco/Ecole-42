#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error" << std::endl;
        return (EXIT_FAILURE);
    }
    try
    {
        PmergeMe merge_insert;
		merge_insert.startProgram(argc, argv);
		
    }
    catch(const std::exception& e)
    {
        std::cout << "Error" << std::endl;
    }
    return (0);
}