/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:28:07 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 13:28:07 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

void PhoneBook::terminate_all()
{
	exit(0);
}

void PhoneBook::add_contact()
{
	char str[1024];
	int	counter = 0;

	if (index >= 8)
		index = 0;
	while (counter < 5)
	{
		if (counter == 0)
			std::cout << "Input first name: ";
		if (counter == 1)
			std::cout << "Input last name: ";
		else if (counter == 2)
			std::cout << "Input nickname: ";
		else if (counter == 3)
			std::cout << "Input phone number: ";
		else if (counter == 4)
			std::cout << "Input darkest secret: ";
		std::cin.getline(str, 1024);
		if (strstr(str, "EXIT") && strlen(str) == 4)
			terminate_all();
		if (str[0] == 0)
			std::cout << "Error! Contact can't have empty fields" << std::endl;
		else
		{
			switch (counter)
			{
				case 0:
				{
					contact[index].set_first_name(str);
					break;
				}
				case 1:
				{
					contact[index].set_last_name(str);
					break;
				}
				case 2:
				{
					contact[index].set_nickname(str);
					break;
				}
				case 3:
				{
					contact[index].set_phone_number(str);
					break;
				}
				case 4:
				{
					contact[index].set_darkest_secret(str);
					break;
				}
				default:
					break;
			}
			counter++;
		}
	}
	index++;
	if (count < 8)
		count++;
}

void PhoneBook::search_contact()
{
	char str[1024];
	int	counter;

	if (count == 0)
	{
		std::cout << "Phone book is empty" << std::endl;
		return ;
	}
	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		if (contact[i].get_first_name().length() > 10)
			std::cout << contact[i].get_first_name().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << contact[i].get_first_name() << "|";
		if (contact[i].get_last_name().length() > 10)
			std::cout << contact[i].get_last_name().substr(0, 9) << "." << "|";
		else
			std::cout << std::setw(10) << contact[i].get_last_name() << "|";
		if (contact[i].get_nickname().length() > 10)
			std::cout << contact[i].get_nickname().substr(0, 9) << "." << "|\n";
		else
			std::cout << std::setw(10) << contact[i].get_nickname() << "|\n";
	}
	std::cout << "Input contact index (1-" << count << "): ";
	std::cin.getline(str, 1024);
	if (strstr(str, "EXIT") && strlen(str) == 4)
		terminate_all();
	counter = atoi(str);
	std::cout << counter << std::endl;
	if (!(counter > 0 && counter <= 8 && counter <= count))
		std::cout << "Incorrect index!" << std::endl;
	else
	{
		counter--;
		std::cout << "First name: " << contact[counter].get_first_name() << std::endl;
		std::cout << "Last name: " << contact[counter].get_last_name() << std::endl;
		std::cout << "Nickname: " << contact[counter].get_nickname() << std::endl;
		std::cout << "Phone number: " << contact[counter].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << contact[counter].get_darkest_secret() << std::endl;
	}
}
