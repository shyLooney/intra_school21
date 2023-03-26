/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:45:59 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/05 16:45:59 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(const std::string);
	FragTrap();
	~FragTrap();
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);

	void highFiveGuys();
};

#endif