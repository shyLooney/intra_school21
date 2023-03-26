/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:28:12 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 13:28:12 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook book;
	char str[1024];

	std::cout << "The program has 3 commands: 'ADD', 'SEARCH', 'EXIT'\n";
	while (1)
	{
		std::cin.getline(str, 1024);
		if (strstr(str, "ADD") && strlen(str) == 3)
			book.add_contact();
		else if (strstr(str, "SEARCH") && strlen(str) == 6)
			book.search_contact();
		else if (strstr(str, "EXIT") && strlen(str) == 4)
			PhoneBook::terminate_all();
	}
	return (0);
}