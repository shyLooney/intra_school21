/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:41:41 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:41:41 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	void announce(void);
	Zombie(std::string);
	~Zombie();
};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif