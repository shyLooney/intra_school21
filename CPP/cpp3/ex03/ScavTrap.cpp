/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:27:49 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 15:27:49 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	hp = 100;
	max_hp = 100;
	ep = 50;
	dmg = 20;
	std::cout << "ScavTrap Constructor called\n";
}

ScavTrap::ScavTrap()
{
	name = "default";
	hp = 100;
	max_hp = 100;
	ep = 50;
	dmg = 20;
	std::cout << "ScavTrap default constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap& sc_tr)
{
	*this = sc_tr;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

void ScavTrap::guardGate()
{
	if (hp > 0)
		std::cout << "ScavTrap is now in Gate keeper mode\n";
	else
		std::cout << "ScavTrap is dead:(\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& cl_tr)
{
	hp = cl_tr.get_hp();
	ep = cl_tr.get_ep();
	dmg = cl_tr.get_dmg();
	name = cl_tr.get_name();
	max_hp = cl_tr.get_max_hp();
	return *this;
}

void ScavTrap::attack(const std::string& target)
{
	if (ep > 0 && hp > 0)
	{
		std::cout << "ScavTrap " << name << " attacks "<< target << ", causing " << dmg << " points of damage!\n";
		ep--;
	}
	else
	{
		if (hp <= 0) std::cout << "ScavTrap " << name << " is dead!\n";
		else if (ep <= 0) std::cout << "ScavTrap " << name << " not enough energy!\n";
	}
	printInfo();
}
