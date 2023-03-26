/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:17:51 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:17:51 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::InternException::what() const throw() 
{
	return ("Error form!\n");
}

Intern::Intern()
{

}

Intern::~Intern()
{

}

Intern::Intern(const Intern& sc)
{
	*this = sc;
}

Intern& Intern::operator=(const Intern& sc)
{
	(void)sc;
	return *this;
}

Form* Intern::makeForm(const std::string& form, const std::string& br)
{
	int	i = 0;
	Form *var;
	std::string str[3] = {"presidential", "robotomy", "shrubbery"};
	Form* (Intern::*foo[3])(const std::string) = {&Intern::back_pr, &Intern::back_rr, &Intern::back_sc};

	while (i < 3 && form.find(str[i]) == std::string::npos)
		i++;
	if (i == 3)
		throw InternException();
	var = (this->*foo[i])(br);
	std::cout << "Intern creates " <<  var->getName() << ".\n";
	return var;
}

Form* Intern::back_pr(const std::string br)
{
	PresidentialPardonForm *pr = new PresidentialPardonForm(br);
	return pr;
}

Form* Intern::back_rr(const std::string br)
{
	RobotomyRequestForm *rr = new RobotomyRequestForm(br);
	return rr;
}

Form*  Intern::back_sc(const std::string br)
{
	ShrubberyCreationForm *sc = new ShrubberyCreationForm(br);
	return sc;
}
