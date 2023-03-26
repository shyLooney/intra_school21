/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:20:25 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:20:25 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __Form_HPP__
#define __Form_HPP__

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name; 
	const int grade_sign;
	const int grade_execute;
	bool is_signed;
public:
	Form();
	Form(const std::string, int, int);
	~Form();
	Form(const Form&);
	Form& operator=(const Form&);

	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool getSigned() const;
	void setSigned(const bool);
	int beSigned(Bureaucrat&);
	virtual void execute(Bureaucrat const &) const = 0;
	void	tryExecute(const Bureaucrat&) const;
	
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

std::ostream& operator<<(std::ostream&, const Form&);

#endif