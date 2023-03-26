/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:23 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:23 by dmacmill         ###   ########.fr       */
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

	Fixed& operator=(const Fixed& fix);
	int toInt() const;
	float toFloat() const;
	int getVal() const;

	Fixed operator+(Fixed&);
	Fixed operator-(Fixed&);
	Fixed operator*(Fixed&);
	Fixed operator/(Fixed&);

	Fixed operator+(const Fixed &);
	Fixed operator-(const Fixed&);
	Fixed operator*(const Fixed&);
	Fixed operator/(const Fixed&);

	bool operator>(Fixed&);
	bool operator<(Fixed&);
	bool operator>=(Fixed&);
	bool operator<=(Fixed&);
	bool operator==(Fixed&);
	bool operator!=(Fixed&);

	bool operator>(const Fixed&);
	bool operator<(const Fixed&);
	bool operator>=(const Fixed&);
	bool operator<=(const Fixed&);
	bool operator==(const Fixed&);
	bool operator!=(const Fixed&);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed&, Fixed&);
	static const Fixed& min(Fixed const&, Fixed const&);

	static Fixed& max(Fixed&, Fixed&);
	static const Fixed& max(const Fixed&, Fixed const&);

};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);

#endif