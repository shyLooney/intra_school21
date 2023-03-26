/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:54:57 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 18:54:57 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data* data = new Data();

	data->num = 100;
	std::cout << "Data in struct = " << data->num << std::endl;
	std::cout << "Original pointer = " << data << std::endl;

	uintptr_t ptr = serialize(data);
	std::cout << "Serialized pointer = " << ptr << std::endl;
	
	data = deserialize(ptr);
	std::cout << "Deserialized pointer = " << data << std::endl;
	std::cout << "Data in struct = " << data->num << std::endl;
	delete data;
	return 0;
}