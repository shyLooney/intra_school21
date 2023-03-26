/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:25:14 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/30 14:05:25 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

#include <iostream>

template <typename T>
void iter(T const * arr, int len, void (*foo)(T const &))
{
	for (int i = 0; i < len; i++)
		foo(*(arr + i));
}

#endif