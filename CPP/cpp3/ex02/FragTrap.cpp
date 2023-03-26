/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:45:56 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 16:45:56 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	name = "default";
	hp = 100;
	max_hp = 100;
	ep = 100;
	dmg = 30;
	std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hp = 100;
	max_hp = 100;
	ep = 100;
	dmg = 30;
	std::cout << "FragTrap Constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called\n";
}

FragTrap::FragTrap(const FragTrap& fr_tr)
{
	*this = fr_tr;
}

FragTrap& FragTrap::operator=(const FragTrap& fr_tr)
{
	this->hp = fr_tr.hp;
	this->max_hp = fr_tr.max_hp;
	this->ep = fr_tr.ep;
	this->dmg = fr_tr.dmg;
	this->name = fr_tr.name;
	return *this;
}

void FragTrap::highFiveGuys()
{
	std::cout << "Hello! What\'s about high five?:3\n";
}