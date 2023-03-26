/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:57 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:43:57 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << name << " joined the battle.\n";
	this->name = name;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	std::cout << name << " get " << weapon.getType() << std::endl;
	this->weapon = &weapon;
}

HumanB::~HumanB()
{
	std::cout << name << " died.\n";
}