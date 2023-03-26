/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:15:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/30 17:46:01 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	const int N = 10; 
	std::vector<int> arr(N);

    srand(time(NULL));
	
	std::cout << "Vector: ";
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 5;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
		
	try
	{
		easyfind(arr, 10);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	try
	{
		easyfind(arr, 3);
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}
	
	return 0;
}