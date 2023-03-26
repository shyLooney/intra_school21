/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:53:33 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 14:53:33 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	name = "default";
	hp = 100;
	max_hp = 100;
	ep = 100;
	dmg = 30;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hp(10), ep(10), dmg(0), max_hp(hp)
{
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &cl_tr)
{
	*this = cl_tr;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& cl_tr)
{
	hp = cl_tr.get_hp();
	ep = cl_tr.get_ep();
	dmg = cl_tr.get_dmg();
	name = cl_tr.get_name();
	max_hp = cl_tr.get_max_hp();
	return *this;
}

void ClapTrap::printInfo()
{
	std::cout << "ClapTrap " << name << " energy: " << ep << ", health: " << hp << ", damage: " << dmg << ".\n";
}

unsigned int ClapTrap::get_dmg() const
{
	return dmg;
}

unsigned int ClapTrap::get_ep() const
{
	return ep;
}

unsigned int ClapTrap::get_hp() const
{
	return hp;
}

std::string ClapTrap::get_name() const
{
	return name;
}

unsigned int ClapTrap::get_max_hp() const
{
	return (max_hp);
}	

void ClapTrap::attack(const std::string& target)
{
	if (ep > 0 && hp > 0)
	{
		std::cout << "ClapTrap " << name << " attacks "<< target << ", causing " << dmg << " points of damage!\n";
		ep--;
	}
	else
	{
		if (hp <= 0) std::cout << "ClapTrap " << name << " is dead!\n";
		else if (ep <= 0) std::cout << "ClapTrap " << name << " not enough energy!\n";
	}
	printInfo();
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hp != 0)
	{
		std::cout << "ClapTrap " << name << " take "<< amount << " points of damage!\n";
		if (hp <= amount)
		{
			std::cout << "ClapTrap " << name << " Wasted...\n";
			hp = 0;
		}
		else
		{
			hp -= amount;
		}
	}
	else
		std::cout << "ClapTrap " << name << " is dead!\n";
	printInfo();
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (ep > 0 && hp > 0)
	{
		std::cout << "ClapTrap " << name << " get "<< amount << " hit points back!\n";
		if (hp + amount > max_hp)
			hp = max_hp;
		else
			hp += amount;
		ep--;
	}
	else
	{
		if (hp <= 0) std::cout << "ClapTrap " << name << " is dead!\n";
		else if (ep <= 0) std::cout << "ClapTrap " << name << " not enough energy!\n";
	}
	printInfo();
}