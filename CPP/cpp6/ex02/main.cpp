/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:58:19 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 18:58:19 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>


Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);


int main()
{
	Base* base = generate();
	
	identify(base);
	identify(*base);

	delete base;
	return 0;
}

void	identify(Base& p)
{
	A a;
	B b;
	C c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "It's A!";
	}
	catch(const std::exception& e)
	{
		try
		{
			b = dynamic_cast<B&>(p);
			std::cout << "It's B!\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				c = dynamic_cast<C&>(p);
				std::cout << "It's C!\n";
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		
	}
	
}

void	identify(Base* p)
{
	A* a;
	B* b;
	C* c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a != NULL)
		std::cout << "It's A!\n";
	else if (b != NULL)
		std::cout << "It's B!\n";
	else
		std::cout << "It's C!\n";
}

Base* generate(void)
{
	int x;

	srand(time(NULL));
  	x = rand() % 3;
	
	if (x == 1)
	{
		std::cout << "Create A!\n";
		return (new A());
	}
	else if (x == 2)
	{
		std::cout << "Create B!\n";
		return (new B());
	}
	std::cout << "Create C!\n";
	return (new C());
}
