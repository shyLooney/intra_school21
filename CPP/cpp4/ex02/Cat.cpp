/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:35 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:35 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Default constructor class: Cat" << std::endl;
	brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "Destructor class: Cat" << std::endl;
	delete brain;
}

Cat::Cat(const Cat& anim)
{
	*this = anim;
}

Brain* Cat::getBrain() const
{
	return brain;
}

Cat& Cat::operator=(const Cat& anim)
{
	this->brain = new Brain(*anim.brain);
	type = anim.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow meow...\n";
}