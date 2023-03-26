/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:17:54 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:17:54 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>
#include <algorithm>


class Intern
{
private:

public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	
	Form* makeForm(const std::string&, const std::string&);
	Form* back_pr(const std::string);
	Form* back_rr(const std::string);
	Form*  back_sc(const std::string);

	class InternException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

#endif