/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:18:03 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:18:03 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form(target, 25, 5)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pr)
{
	*this = pr;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& pr)
{
	setSigned(pr.getSigned());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	tryExecute(executor);
	std::cout << getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
