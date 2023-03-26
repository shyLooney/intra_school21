/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:48:18 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 18:48:18 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

int dot_null(std::string str)
{
	int aft_dot = 0;
	int bef_dot = 0;
	int	i = 0;
	
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && isdigit(str[i]))
	{
		bef_dot++;
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && isdigit(str[i]))
	{
		if (str[i] != '0' && bef_dot + aft_dot < 6)
			return (0);
		aft_dot++;
		i++;
	}
	return (1);
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return 0;
	std::string str(argv[1]);
	char d;
	int	c;
	float a;
	double b;
	bool info;

	try
	{
		a = std::stof(str);
		info = dot_null(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error!" << '\n';
		return (0);
	}

	b = static_cast<double> (a);
	c = static_cast<int> (a);
	d = static_cast<char> (a);
	
	if (c < 0 || c > 127 || !info || std::isinf(b) || std::isnan(b) || std::isinf(a) || std::isnan(a))
		std::cout << "char: impossible" << std::endl;
	else if ((c >= 0 && c < '!') || c == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << d << std::endl;
	
	if (std::isinf(b) || std::isinf(a) || std::isnan(b) || std::isnan(a))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << c << std::endl;
	
	std::cout << "float: " << a ;
	if (info && !std::isinf(a) && !std::isnan(b))
		std::cout << ".0"; 
	std::cout <<"f" << std::endl;

	std::cout << "double: " << b;
	if (info && !std::isinf(a) && !std::isnan(b))
		std::cout << ".0"; 
	std::cout << std::endl;
	return (0);
}