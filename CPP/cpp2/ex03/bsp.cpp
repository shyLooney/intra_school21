/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:14 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:14 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed x1 = a.getX(), y1 = a.getY();
	Fixed x2 = b.getX(), y2 = b.getY();
	Fixed x3 = c.getX(), y3 = c.getY();
	Fixed x0 = point.getX(), y0 = point.getY();
	if ((((x1-x0)*(y2-y1)-(x2-x1)*(y1-y0) > 0)
		&& ((x2-x0)*(y3-y2)-(x3-x2)*(y2-y0) > 0)
		&& ((x3-x0)*(y1-y3)-(x1-x3)*(y3-y0) > 0)) || (((x1-x0)*(y2-y1)-(x2-x1)*(y1-y0) < 0)
		&& ((x2-x0)*(y3-y2)-(x3-x2)*(y2-y0) < 0)
		&& ((x3-x0)*(y1-y3)-(x1-x3)*(y3-y0) < 0)))
		return (true);
	return (false);
}