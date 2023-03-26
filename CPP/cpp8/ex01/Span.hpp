/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:49:15 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 15:53:59 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include <algorithm>

class Span
{
private:
	unsigned int	n;
	std::vector<int> vec;
public:
	Span();
	~Span();
	Span(const Span&);
	Span& operator=(const Span&);

	Span(std::size_t);
	void addNumber(int);
	int getSize() const;
	std::vector<int> getVector() const;
	int shortestSpan();
	int longestSpan();
	void addRange(std::vector<int>::iterator left, std::vector<int>::iterator right);
};

#endif