/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:18:05 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 12:52:00 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int j = 1; j < argc; j++)
	{
		for (int i = 0; argv[j][i]; i++)
		{
			if (argv[j][i] >= 'a' && argv[j][i] <= 'z')
				argv[j][i] -= 32;
			std::cout << argv[j][i];
		}
	}
	return (0);
}