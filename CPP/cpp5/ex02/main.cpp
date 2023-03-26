/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:20:36 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:20:36 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	ShrubberyCreationForm sc("D-28");
	RobotomyRequestForm rr("C-28");
	PresidentialPardonForm pr("B-28");

	std::cout << sc << std::endl;
	std::cout << rr << std::endl;
	std::cout << pr << std::endl;


	Bureaucrat br("Sema", 1);
	
	try
	{
		br.signForm(sc);
		br.executeForm(sc);
	
		br.signForm(rr);
		br.executeForm(rr);
		
		br.signForm(pr);
		br.executeForm(pr);
}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}