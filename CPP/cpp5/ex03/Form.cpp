/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:17:44 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:17:44 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException()
{
	
}

Form::GradeTooLowException::GradeTooLowException()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form GradeTooHighException called");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form GradeTooLowException called");
}

Form::Form(const std::string name, int grade_sign, int grade_execute) : name(name), grade_sign(grade_sign), grade_execute(grade_execute)
{
	is_signed = false;
	if (grade_sign < 1 || grade_execute < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
		throw GradeTooLowException();
}

Form::Form() : name("default"), grade_sign(1), grade_execute(1)
{
	is_signed = false;
}

Form::~Form()
{

}

Form::Form(const Form& br) : name(br.getName()), grade_sign(br.getGradeSign()), grade_execute(br.getGradeExecute())
{
	*this = br;
}

Form& Form::operator=(const Form& br)
{
	is_signed = br.getSigned();
	return *this;
}

int Form::getGradeSign() const
{
	return grade_sign;
}

int Form::getGradeExecute() const
{
	return grade_execute;
}

const std::string Form::getName() const
{
	return name;
}

bool Form::getSigned() const
{
	return is_signed;
}

void Form::setSigned(const bool bol)
{
	is_signed = bol;
}


std::ostream& operator<<(std::ostream& os, const Form& br)
{
	os << br.getName() << ", Form gradeSign " << br.getGradeSign() << ", Form gradeExecute " << br.getGradeExecute() << ".";
	return os;
}

int Form::beSigned(Bureaucrat& br)
{
	if (grade_sign < 1 || grade_execute < 1 || br.getGrade() < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150 || br.getGrade() > 150)
		throw GradeTooLowException();
	if (br.getGrade() <= grade_sign)
	{
		is_signed = true;	
		return (1);
	}
	return(0);
}

void Form::tryExecute(const Bureaucrat& br) const
{
	if (grade_sign < 1 || grade_execute < 1 || br.getGrade() < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150 || br.getGrade() > 150)
		throw GradeTooLowException();
	if (!(is_signed && br.getGrade() <= grade_execute))
		throw GradeTooLowException();
}