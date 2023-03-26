/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:44 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:43:44 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : weapon(weapon)
{
	std::cout << name << " joined the battle.\n";
	this->name = name;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon& weapon)
{
	std::cout << name << " get " << weapon.getType() << std::endl;
	this->weapon = weapon;
}

HumanA::~HumanA()
{
	std::cout << name << " died.\n";
}