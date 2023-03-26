/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:35 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:35 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __POINT_HPP__
#define __POINT_HPP__

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const Point&);
	Point(const float, const float);
	~Point();
	Point& operator=(const Point&);

	const Fixed& getX() const;
	const Fixed& getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif