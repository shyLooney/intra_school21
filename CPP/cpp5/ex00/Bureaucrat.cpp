/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:43:26 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 15:43:26 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{

}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException called");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException called");
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::increment()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrement()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

Bureaucrat::Bureaucrat() : name("default"), grade(0)
{

}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat& br)
{
	*this = br;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& br)
{
	grade = br.getGrade();
	return *this;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

const std::string Bureaucrat::getName() const
{
	return name;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
	return os;
}
