/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:00 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:18:00 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern someRandomIntern;
	Bureaucrat sema("Sema", 3);
	Form* form;

	try
	{
		form = someRandomIntern.makeForm("shrubbery request", "C-28");
		sema.signForm(*form);
		sema.executeForm(*form);
        delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
    
	std::cout << "\n\n";

	try
	{
		form = someRandomIntern.makeForm("robotomy request", "robotomy");
		sema.signForm(*form);
		sema.executeForm(*form);
        delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n";

	try
	{
		form = someRandomIntern.makeForm("presidential request", "presidential");
		sema.signForm(*form);
		sema.executeForm(*form);
        delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n";

	try
	{
		form = someRandomIntern.makeForm("aaaa request", "C-28");
		sema.signForm(*form);
		sema.executeForm(*form);
        delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}
