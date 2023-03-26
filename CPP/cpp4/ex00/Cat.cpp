/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:22 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:22 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Default constructor class: Cat" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Destructor class: Cat" << std::endl;
}

Cat::Cat(const Cat& anim)
{
	*this = anim;
}

Cat& Cat::operator=(const Cat& anim)
{
	type = anim.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow meow...\n";
}