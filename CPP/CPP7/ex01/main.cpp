#include "iter.hpp"

int main( void ) {
    int i[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	char c[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string str[4] = {"Bob", "Jean", "Juan", "Alice"};
	
	iter(i, 10, print<int>);
	std::cout << std::endl;
	iter(c, 5, print<char>);
	std::cout << std::endl;
	iter(str, 4, print<std::string>);
}