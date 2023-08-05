#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try
	{
		Span sp = Span(10000);
		srand(time(0));
		for (int i = 0; i < 10000; i++)
		{
			sp.addNumber(rand() % INT_MAX);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int> tmp;
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
			tmp.push_back(rand() % INT_MAX);
		Span sp = Span(20000);
		sp.addRange(tmp.begin(), tmp.end());
		std::cout << "addRange 1" << std::endl;
		sp.addRange(tmp.begin(), tmp.end());
		std::cout << "addRange 2" << std::endl;
		sp.addRange(tmp.begin(), tmp.end());
		std::cout << "addRange 3" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}