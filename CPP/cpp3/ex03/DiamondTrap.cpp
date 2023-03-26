/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:03:04 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:03:04 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	name = "default";
	ClapTrap::name = "default_clap_name";
	hp = FragTrap::hp;
	ep = ScavTrap::ep;
	dmg = FragTrap::dmg;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	ClapTrap::name = name + "_clap_name";
	this->name = name;
	hp = FragTrap::hp;
	ep = ScavTrap::ep;
	dmg = FragTrap::dmg;
}

void DiamondTrap::attack(const std::string& str)
{
	ScavTrap::attack(str);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << name << " ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& di_tr)
{
	*this = di_tr;	
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& di_tr)
{
	name = di_tr.name;
	dmg = di_tr.dmg;
	ep = di_tr.ep;
	max_hp = di_tr.max_hp;
	hp = di_tr.hp;
	return *this;
}