/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:15 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:43:15 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;
	Zombie* zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].set_name(name);
	return zombie;
}