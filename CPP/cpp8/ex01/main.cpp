/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:49:13 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 10:26:52 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	
	try
	{	
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(10);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	
	for (int i = 0; i < sp.getSize(); i++)
	{
		std::cout << sp.getVector()[i] << " ";
	}
	
	std::cout << std::endl << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::vector<int> contain(10000);
    
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
		contain[i] = rand();

	Span bigSp = Span(10000);
	try
	{
		bigSp.addRange(contain.begin(), contain.end());
		std::cout << std::endl << bigSp.shortestSpan() << std::endl;
		std::cout << bigSp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		bigSp.addNumber(444);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span test_Cp1(1);
	test_Cp1.addNumber(4);
	try
	{
		std::cout << test_Cp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Vector size = 1, longest: " << e.what() << '\n';
	}
	
	try
	{
		std::cout << test_Cp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Vector size = 1, shortest: " << e.what() << '\n';
	}
	
	return 0;
}