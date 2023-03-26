/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:55:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 18:55:02 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t dot;

	dot = reinterpret_cast<uintptr_t>(ptr);
	return dot;
}

Data* deserialize(uintptr_t raw)
{
	Data* data;
	data = reinterpret_cast<Data*>(raw);
	return (data);
}
