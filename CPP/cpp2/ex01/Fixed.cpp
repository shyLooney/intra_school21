/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:30:50 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:30:50 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fix)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fix;
}

Fixed::Fixed(const int num) : value(num * (1 << BITS))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value(roundf(num * (1 << BITS)))
{
	std::cout << "Float constructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

int Fixed::getRawBits() const
{
	return (value);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fix)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = fix.getRawBits();
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

std::ostream& operator<<(std::ostream& os, const Fixed& fix)
{
	os << fix.toFloat();
	return os;
}