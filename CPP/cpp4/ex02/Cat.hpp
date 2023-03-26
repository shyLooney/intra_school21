/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:22 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:22 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CAT_HPP__
#define __CAT_HPP__

#include "Animal.hpp"

class Brain;

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	void makeSound() const;
	Brain* getBrain() const;

};

#endif