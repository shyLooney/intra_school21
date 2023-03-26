/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:44:32 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:44:32 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <string>
#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon(std::string);
	Weapon();
	const std::string& getType();
	void setType(std::string);
};

#endif