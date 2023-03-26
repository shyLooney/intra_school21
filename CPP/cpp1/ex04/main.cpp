/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:53 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:44:53 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

void ft_replace(std::string& buf, std::string s1, std::string s2)
{
	size_t index;

	index = buf.find(s1);
	while (index != std::string::npos)
	{
		buf.erase(index, s1.length());
		buf.insert(index, s2);
		index = buf.find(s1, index + s1.length() + 1);
	}
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Error! Example: ./files <files_name> <substr> <str>\n";
		return (0);
	}
	std::string	buf;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream fin;
	std::ofstream fout;

	if (s1 == "")
	{
		std::cerr << "Error! Empty string" << std::endl;
		return (0);
	}

	fin.open(argv[1]);

	if (!fin.is_open())
	{
		std::cerr << "File open error" << std::endl;
		return (0);
	}

	fout.open(argv[1] + std::string(".replace"));
	if (!fout.is_open())
	{
		std::cerr << "Can't create file" << std::endl;
		fin.close();
		return (0);
	}

	std::getline(fin, buf, '\0');
	if (s1 != s2)
		ft_replace(buf, s1, s2);

	fout << buf;;
	std::cout << buf << std::endl;
	fin.close();
	fout.close();
	return (0);
}