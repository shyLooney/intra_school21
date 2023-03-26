/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:31:18 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:31:18 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getVal() const
{
	return value;
}

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed& fix)
{
	*this = fix;
}

Fixed::Fixed(const int num) : value(num * (1 << BITS))
{

}

Fixed::Fixed(const float num) : value(roundf(num * (1 << BITS)))
{

}

Fixed::~Fixed()
{

}

Fixed& Fixed::operator=(const Fixed& fix)
{
	value = fix.getVal();
	return *this;
}

int Fixed::toInt() const
{
	return (value / 256);
}

float Fixed::toFloat() const
{
	return ((float)value / 256);
}

Fixed Fixed::operator+(Fixed& a)
{
	return Fixed(this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(Fixed& a)
{
	return Fixed(this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(Fixed& a)
{
	return Fixed(this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(Fixed& a)
{
	return Fixed(this->toFloat() / a.toFloat());
}

Fixed Fixed::operator+(const Fixed& a)
{
	return Fixed(this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(const Fixed& a)
{
	return Fixed(this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(const Fixed& a)
{
	return Fixed(this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(const Fixed& a)
{
	return Fixed(this->toFloat() / a.toFloat());
}

bool Fixed::operator>(Fixed& a)
{
	if (value > a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator<(Fixed& a)
{
	if (value < a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator>=(Fixed& a)
{
	if (value >= a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator<=(Fixed& a)
{
	if (value <= a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator>(const Fixed& a)
{
	if (value > a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator<(const Fixed& a)
{
	if (value < a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator>=(const Fixed& a)
{
	if (value >= a.toFloat())
		return (1);
	return (0);
}

bool Fixed::operator<=(const Fixed& a)
{
	if (value <= a.toFloat())
		return (1);
	return (0);
}

Fixed& Fixed::operator++()
{
	++value;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++value;
	return tmp;
}

Fixed& Fixed::operator--()
{
	--value;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--value;
	return tmp;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	return (b);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return os;
}