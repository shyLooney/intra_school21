/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:18:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 17:18:02 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Default constructor class: WrongCat" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor class: WrongCat" << std::endl;
}

WrongCat::WrongCat(const WrongCat& anim)
{
	*this = anim;
}

WrongCat& WrongCat::operator=(const WrongCat& anim)
{
	type = anim.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow meow meow...\n";
}