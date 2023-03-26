/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:43:21 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 15:43:21 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bureaucrat("Name", 1);
	try
	{
		bureaucrat.increment();
	}
	catch(const Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	catch (const Bureaucrat::GradeTooHighException &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << bureaucrat << std::endl;

	Bureaucrat bureaucrat2("Name2", 150);
	try
	{
		bureaucrat2.decrement();
	}
	catch(const Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	std::cout << bureaucrat2 << std::endl << std::endl;
	
	try
	{
		Bureaucrat br("Name", -1);
	}
	catch(const Bureaucrat::GradeTooHighException &ex)
	{
		std::cerr << ex.what() << '\n';
	}

	try
	{
		Bureaucrat br("Name", 152);
	}
	catch(const Bureaucrat::GradeTooLowException &ex)
	{
		std::cerr << ex.what() << '\n';
	}
	return 0;
}