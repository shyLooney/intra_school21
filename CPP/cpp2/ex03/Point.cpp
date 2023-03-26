/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:31 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:31 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) 
{

}

Point::Point(const Point& point) : x(point.getX()), y(point.getY())
{
	
}

Point::Point(const float x, const float y) : x(x), y(y)
{

}

Point::~Point()
{

}

const Fixed& Point::getX() const
{
	return (x);
}

const Fixed& Point::getY() const
{
	return (y);
}

Point& Point::operator=(const Point& fix)
{
	(void)fix;
	return *this;
}