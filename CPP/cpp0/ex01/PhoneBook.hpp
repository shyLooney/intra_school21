/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:24:14 by dmacmill          #+#    #+#             */
/*   Updated: 2022/09/27 12:24:14 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <cstring>
#include <iomanip>

class PhoneBook
{
private:
	Contact	contact[8];
	int index;
	int count;
public:
	void add_contact();
	void search_contact();
	static void terminate_all();
	PhoneBook();
};

#endif