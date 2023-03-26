/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:02:51 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:02:51 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap cl_tr("aboba");
	cl_tr.whoAmI();

	cl_tr.attack("abobu");
	for (int i = 0; i < 8; i++)
		cl_tr.beRepaired(1);
	cl_tr.takeDamage(8);
	cl_tr.beRepaired(5);
	cl_tr.takeDamage(10);
	cl_tr.attack("assasin");
	cl_tr.beRepaired(1);
	cl_tr.highFiveGuys();
	cl_tr.attack("enemy");
	
	return (0);
}
