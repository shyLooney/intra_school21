/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:42:49 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:42:49 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 3;
	Zombie* zombie = zombieHorde(N, "Sema");
	
	for (int i = 0; i < N; i++)
		zombie[i].announce();

	delete[] zombie;
	return 0;
}