/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:13:17 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 14:13:17 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include "Animal.hpp"

class Brain
{
protected:
	std::string type;
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain&);
	Brain& operator=(const Brain&);
	std::string getIdea(const int i) const;
};

#endif