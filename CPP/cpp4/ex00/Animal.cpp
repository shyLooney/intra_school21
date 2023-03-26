/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:08 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:08 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << "Default constructor class: Animal" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Destructor class: Animal" << std::endl;
}

Animal::Animal(const Animal& anim)
{
	*this = anim;
}

Animal& Animal::operator=(const Animal& anim)
{
	type = anim.getType();
	return *this;
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "default sound...\n";
}