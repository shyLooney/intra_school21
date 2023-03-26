/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:49:17 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/31 15:55:17 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : n(0) {}

Span::Span(std::size_t n) : n(n) {}

int Span::getSize() const { return n; }

std::vector<int> Span::getVector() const { return vec; }

Span::~Span()
{
	
}

Span::Span(const Span& sp)
{
	*this = sp;
}

Span& Span::operator=(const Span& sp)
{
	if (&sp == this)
		return *this;
	n = sp.getSize();
	vec = sp.getVector();
	return *this;
}

void Span::addNumber(int num)
{
	if (vec.size() == n)
		throw std::exception();
	vec.push_back(num);
}

void Span::addRange(std::vector<int>::iterator left, std::vector<int>::iterator right)
{
	if (vec.size() + distance(left, right) > n)
		throw std::exception();
	vec.insert(vec.end(), left, right);
	n = vec.size();
}

int Span::shortestSpan()
{
	if (vec.size() < 2)
		throw std::exception();
	int	shortest = abs(vec[0] - vec[1]);

	for (std::size_t i = 0; i < vec.size(); i++)
	{
		for (std::size_t j = 0; j < vec.size(); j++)
		{
			if (shortest > abs(vec[j] - vec[i]) && i != j && abs(vec[j] - vec[i]) != 0)
				shortest = abs(vec[j] - vec[i]);
		}
	}
	return shortest;
}

int Span::longestSpan()
{
	if (vec.size() < 2)
		throw std::exception();
	int	max = vec[0];
	int min = max;
	
	for (std::size_t i = 0; i < vec.size(); i++)
	{
		if (max < vec[i])
			max = vec[i];
		if (min > vec[i])
			min = vec[i];
	}
	return max - min;
}