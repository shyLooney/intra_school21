/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:17:36 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:17:36 by dmacmill         ###   ########.fr       */
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

void Bureaucrat::signForm(Form& form)
{	
	if (form.getGradeSign() < 1 || form.getGradeExecute() < 1 || grade < 1)
		throw GradeTooHighException();
	if (form.getGradeSign() > 150 || form.getGradeExecute() > 150 || grade > 150)
		throw GradeTooLowException();
	if (!form.getSigned() && form.beSigned(*this))
		std::cout << name << " signed " << form.getName() << ".\n";
	else if (form.getSigned())
		std::cout << name << " couldn't sign " << form.getName() << " because " << "already signed.\n";
	else
		std::cout << name << " couldn't sign " << form.getName() << " because " << "low grade.\n";
}

void Bureaucrat::executeForm(Form& form)
{
	form.execute(*this);
	std::cout << name << " executed " << form.getName() << std::endl;
}