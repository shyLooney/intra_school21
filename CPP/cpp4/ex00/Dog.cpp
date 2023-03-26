/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:16 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:16 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Default constructor class: Dog" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Destructor class: Dog" << std::endl;
}

Dog::Dog(const Dog& anim)
{
	*this = anim;
}

Dog& Dog::operator=(const Dog& anim)
{
	type = anim.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof woof...\n";
}