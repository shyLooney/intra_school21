/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:46:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:02 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap cl_tr("aboba");
	cl_tr.attack("abobu");
	for (int i = 0; i < 8; i++)
		cl_tr.beRepaired(1);
	cl_tr.takeDamage(8);
	cl_tr.beRepaired(5);
	cl_tr.takeDamage(10);
	cl_tr.attack("assasin");
	cl_tr.beRepaired(1);
	cl_tr.highFiveGuys();
	return (0);
}