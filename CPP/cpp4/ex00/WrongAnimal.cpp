/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:14 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:14 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "WrongAnimal";
	std::cout << "Default constructor class: WrongAnimal" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor class: WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& anim)
{
	*this = anim;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& anim)
{
	type = anim.getType();
	return *this;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "default sound...\n";
}