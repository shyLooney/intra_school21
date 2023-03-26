/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:15:00 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/30 17:44:43 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template<typename T>
void easyfind(T& arr, int value)
{
	typename T::iterator a = std::find(arr.begin(), arr.end(), value);
	if (a == std::end(arr))
		throw std::exception();
	std::cout << value << " found!\n";
}