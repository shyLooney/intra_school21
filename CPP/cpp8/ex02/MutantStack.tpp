/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:51:18 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 15:51:18 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack()
{

}

template<typename T>
MutantStack<T>::~MutantStack()
{

}
	
template<typename T>
MutantStack<T>::MutantStack(const MutantStack& ms)
{
	*this = ms;
}
	
template<typename T>
std::stack<T>& MutantStack<T>::operator=(const std::stack<T>& ms)
{
	if (this != &ms)
		*this = ms;
	return *this;
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

template<typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}