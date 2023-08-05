#include "MutantStack.hpp"
#include "list"

int main()
{
    // std::list<int> mstack;
    // mstack.push_back(5);
    // mstack.push_back(17);
    // std::cout << mstack.back() << std::endl;
    // mstack.pop_back();
    // std::cout << mstack.size() << std::endl;
    // mstack.push_back(3);
    // mstack.push_back(5);
    // mstack.push_back(737);
    // mstack.push_back(0);
    // std::list<int>::iterator it = mstack.begin();
    // std::list<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);

    try
	{
		MutantStack<int> mystack;
		for (int i=0; i<10; i++) mystack.push(i);

		MutantStack<int>::reverse_iterator it = mystack.rbegin();
		MutantStack<int>::reverse_iterator ite = mystack.rend();

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}