/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:51:15 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 15:51:15 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <vector>
#include <list>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
private:

public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack&);
	std::stack<T>& operator=(const std::stack<T>&);

	iterator begin();
	iterator end();

};

#include "MutantStack.tpp"

#endif