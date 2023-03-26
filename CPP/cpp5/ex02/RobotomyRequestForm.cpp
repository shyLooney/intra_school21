/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:21:08 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:21:08 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form(target, 72, 45)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rr)
{
	*this = rr;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rr)
{
	setSigned(rr.getSigned());
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	tryExecute(executor);
	std::cout << getName() << " has been robotomized successfully 50% of the time.\n";
}