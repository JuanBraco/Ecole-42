#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>


Base *generate(void)
{
	srand ( time(0) );
	int		i = (rand() % 3 + 1);
	switch (i)
	{
		case 1 :
			std::cout << "new A is generated" << std::endl;
			return (new A());
		case 2 :
			std::cout << "new B is generated" << std::endl;
			return (new B());
		case 3 :
			std::cout << "new C is generated" << std::endl;
			return (new C());
	}
	return (NULL);
}

void identify(Base* p)
{
	if (p == NULL)
		std::cout << "Base pointer is NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "Base pointer is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Base pointer is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Base pointer is C" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "Reference to Base is A\n";
		static_cast<void>(a);
	}
	catch(const std::exception& e)
	{

	}
	try 
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "Reference to Base is B\n";
		static_cast<void>(b);
	}
	catch(const std::exception& e)
	{
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "Reference to Base is C\n";
		static_cast<void>(c);
	}
	catch(const std::exception& e)
	{

	}
}

int main(void) {
    Base *p = generate();
	identify(p);
	identify(*p);
	delete p;

    return 0;
}