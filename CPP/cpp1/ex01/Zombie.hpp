/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:43:03 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:43:03 by dmacmill         ###   ########.fr       */
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
	~Zombie();
	void announce(void);
	std::string get_name();
	void set_name(std::string);
};

Zombie* zombieHorde(int N, std::string name);

#endif