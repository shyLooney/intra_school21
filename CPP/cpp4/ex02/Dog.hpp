/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:24 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:24 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __DOG_HPP__
#define __DOG_HPP__

#include "Animal.hpp"

class Brain;

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	void makeSound() const;
	Brain* getBrain() const;
};

#endif