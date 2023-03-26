/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:53:36 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 14:53:36 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <string>
#include <iostream>

class ClapTrap
{
private:
	std::string name;
	unsigned int hp;
	unsigned int ep;
	unsigned int dmg;
	unsigned int max_hp;
public:
	ClapTrap(const std::string);
	ClapTrap(const ClapTrap&);
	ClapTrap();
	ClapTrap& operator=(const ClapTrap&);
	~ClapTrap();

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void printInfo();

	unsigned int get_hp() const;
	unsigned int get_ep() const;
	unsigned int get_dmg() const;
	unsigned int get_max_hp() const;
	std::string get_name() const;
};

#endif