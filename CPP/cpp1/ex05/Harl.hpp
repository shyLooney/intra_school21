/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:55:05 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 14:55:20 by dmacmill         ###   ########.fr       */
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
    std::string level;
    void (Harl::*foo[4])();

    void debug();
    void info();
    void warning();
    void error();
public:
    void complain(std::string level);
    Harl();
};

#endif