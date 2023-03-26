/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:30:53 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:30:53 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int BITS = 8;
public:
	Fixed();
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed&);
	~Fixed();

	int getRawBits() const;
	void setRawBits(const int raw);
	Fixed& operator=(const Fixed& fix);
	int toInt() const;
	float toFloat() const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif