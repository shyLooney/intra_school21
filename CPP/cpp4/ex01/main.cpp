/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:33 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:33 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const Cat* orig = new Cat();
	const Cat copy = *orig;

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	j->makeSound();
	i->makeSound();

	delete j;
	delete i;
	delete orig;

	copy.makeSound();
	std::cout << copy.getType() << std::endl;
	std::cout << copy.getBrain()->getIdea(4) << "\n";
	
	std::cout << "\n\n\n";

	Animal** array = new Animal*[10];
	for (int i = 0; i < 5; i++)
		array[i] = new Dog();
	for (int i = 5; i < 10; i++)
		array[i] = new Cat();

	for (int i = 0; i < 10; i++)
		array[i]->makeSound();

	std::cout << "\n\n\n";

	for (int i = 0; i < 10; i++)
		delete array[i];
	delete[] array;
	return 0;
}