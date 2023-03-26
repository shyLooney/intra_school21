/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:37 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:37 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Default constructor class: Dog" << std::endl;
	brain = new Brain();
}

Dog::~Dog()
{
	std::cout << "Destructor class: Dog" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& anim)
{
	*this = anim;
}

Brain* Dog::getBrain() const
{
	return brain;
}

Dog& Dog::operator=(const Dog& anim)
{
	this->brain = new Brain(*anim.brain);
	type = anim.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof woof woof...\n";
}