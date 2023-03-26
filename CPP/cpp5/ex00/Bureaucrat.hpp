/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:43:24 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 15:43:24 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <string>
#include <iostream>
#include <exception>
#include <stdexcept>

class Bureaucrat
{
private:
	const std::string name; 
	int	grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string, int);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat&);
	Bureaucrat& operator=(const Bureaucrat&);

	const std::string getName() const;
	int getGrade() const;
	void increment();
	void decrement();

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		const char* what() const throw();
	};
	
	
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif