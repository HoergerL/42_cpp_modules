#include "MutantStack.hpp"
#include <list>
int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
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
		std::cout << "reverse: " << std::endl;
		MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
		MutantStack<int>::reverse_iterator r_ite = mstack.rend();
		++r_it;
		--r_it;
		while (r_it != r_ite)
		{
			std::cout << *r_it << std::endl;
			++r_it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl << "#####################################" <<std::endl << std::endl;
	}
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << "Top: " << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "reverse: " << std::endl;
		std::list<int>::reverse_iterator r_it = mstack.rbegin();
		std::list<int>::reverse_iterator r_ite = mstack.rend();
		++r_it;
		--r_it;
		while (r_it != r_ite)
		{
			std::cout << *r_it << std::endl;
			++r_it;
		}
		//std::stack<int> s(mstack);
		return 0;
	}
}