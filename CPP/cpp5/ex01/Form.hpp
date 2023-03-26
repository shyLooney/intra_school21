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
	Form(const std::string, const int, const int);
	~Form();
	Form(const Form&);
	Form& operator=(const Form&);

	const std::string getName() const;
	int getGradeSign() const;
	int getGradeExecute() const;
	bool getSigned() const;
	int beSigned(Bureaucrat&);
	
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