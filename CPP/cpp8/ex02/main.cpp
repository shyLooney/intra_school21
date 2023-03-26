/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:51:13 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 15:51:13 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<std::string> stack_s;
	stack_s.push("5");
	stack_s.push("17");
	std::cout << stack_s.top() << std::endl;
	stack_s.pop();
	std::cout << stack_s.size() << std::endl;
	stack_s.push("3");
	stack_s.push("5");
	stack_s.push("737");

	stack_s.push("0");

	MutantStack<std::string>::iterator s1 = stack_s.begin();
	MutantStack<std::string>::iterator s2 = stack_s.end();
	++s1;
	--s1;
	std::cout << std::endl << "String stack:" << std::endl;
	while (s1 != s2)
	{
		std::cout << *s1 << std::endl;
		++s1;
	}

	std::cout << "______________________________________________\n";
	std::cout << std::endl << "int stack:" << std::endl;
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
	std::cout << std::endl << "orig stack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	MutantStack<int> copy = mstack;
	it = mstack.begin();
	ite = mstack.end();

	std::cout << "copy stack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "______________________________________________\n";
	std::cout << std::endl << "List: " << "\n";
	std::list<int> list_stack;
	list_stack.push_back(5);
	list_stack.push_back(17);
	std::cout << list_stack.back() << std::endl;
	list_stack.pop_front();
	std::cout << list_stack.size() << std::endl;
	list_stack.push_back(3);
	list_stack.push_back(5);
	list_stack.push_back(737);

	list_stack.push_back(0);

	
	std::list<int>::iterator iter = list_stack.begin();
	std::list<int>::iterator itera = list_stack.end();
	++iter;
	--iter;
	std::cout << std::endl << "List:" << std::endl;
	while (iter != itera)
	{
		std::cout << *iter << std::endl;
		++iter;
	}

	return 0;
}