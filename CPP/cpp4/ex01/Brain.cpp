/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:30 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:30 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	type = "Brain";
	std::cout << "Default constructor class: Brain" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "brain N" + std::to_string(i);
}

Brain::~Brain()
{
	std::cout << "Destructor class: Brain" << std::endl;
}

Brain::Brain(const Brain& anim)
{
	*this = anim;
}

Brain& Brain::operator=(const Brain& anim)
{
	type = anim.type;
	std::copy(anim.ideas, anim.ideas + 100, ideas);
	return *this;
}

std::string Brain::getIdea(const int i) const
{
	return ideas[i];
}