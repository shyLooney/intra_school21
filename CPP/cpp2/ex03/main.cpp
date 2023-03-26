/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:27 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:27 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	{
		Point a(3.12, 1.43);
		Point b(-3.2, 1);
		Point c(1.72, 6.12);
		Point point(1.42, 3.65);

		std::cout << "A: (" << a.getX() << ";" << a.getY() << ")\t";
		std::cout << "B: (" << b.getX() << ";" << b.getY() << ")\t";
		std::cout << "C: (" << c.getX() << ";" << c.getY() << ")\t";
		std::cout << "Point: (" << point.getX() << ";" << point.getY() << ")\n";
		std::cout << "Result bsp:" << bsp(a, b, c, point) << std::endl;
	}
	{
		Point a;
		Point b(0, 5);
		Point c(5, 0);
		Point point(2, 2);

		std::cout << "A: (" << a.getX() << ";" << a.getY() << ")\t";
		std::cout << "B: (" << b.getX() << ";" << b.getY() << ")\t";
		std::cout << "C: (" << c.getX() << ";" << c.getY() << ")\t";
		std::cout << "Point: (" << point.getX() << ";" << point.getY() << ")\n";
		std::cout << "Result bsp:" << bsp(a, b, c, point) << std::endl;
	}
	{
		Point a;
		Point b(0, 5);
		Point c(5, 0);
		Point point(-2, -2);

		std::cout << "A: (" << a.getX() << ";" << a.getY() << ")\t";
		std::cout << "B: (" << b.getX() << ";" << b.getY() << ")\t";
		std::cout << "C: (" << c.getX() << ";" << c.getY() << ")\t";
		std::cout << "Point: (" << point.getX() << ";" << point.getY() << ")\n";
		std::cout << "Result bsp:" << bsp(a, b, c, point) << std::endl;
	}

	return 0;
}