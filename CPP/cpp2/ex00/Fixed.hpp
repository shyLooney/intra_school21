/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 20:30:36 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/03 20:30:36 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed
{
private:
	int points;
	static const int BITS = 8;
public:
	Fixed();
	Fixed(const Fixed&);
	~Fixed();

	int getRawBits() const;
	void setRawBits(int const raw);
	Fixed& operator=(const Fixed& fix);
};

#endif