/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:05:29 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/30 14:05:30 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void foo(T const & x)
{
	std::cout << x << std::endl;
}

int main() {
	int arr[] = { 0, 1, 2, 3, 4 };
	std::string str[] = {"a", "b", "o", "b", "a"};

	iter( arr, 5, foo );
	iter( str, 5, foo );
	return 0;
}