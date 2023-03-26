/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:19:54 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/01 13:19:54 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>

class Harl
{
private:
    void debug();
    void info();
    void warning();
    void error();
public:
    void complain(std::string level);
};

#endif