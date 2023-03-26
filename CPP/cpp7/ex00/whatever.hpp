/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:25:14 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/30 14:05:44 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T>
T& min(T& a, T& b)
{
	if (a > b)
		return b;
	else
		return a;	
}

template <typename T>
T& max(T& a, T& b)
{
	if (a > b)
		return a;
	else
		return b;	
}

#endif