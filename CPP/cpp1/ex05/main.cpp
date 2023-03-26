/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:55:25 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/01 15:29:52 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    std::string level;
    Harl harl;
    while (1)
    {
        std::cout << "Write to Harl: ";
        std::cin >> level;
        harl.complain(level);
    }
    return 0;
}