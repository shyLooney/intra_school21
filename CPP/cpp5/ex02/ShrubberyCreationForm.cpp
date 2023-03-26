/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:21:16 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/26 17:21:16 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form(target, 145, 137)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& sc)
{
	*this = sc;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& sc)
{
	setSigned(sc.getSigned());
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	tryExecute(executor);
	std::ofstream fout;
	try
	{
		fout.open(getName() + std::string("_shrubbery"));
		fout <<		"              #\n"
					"             ***"
					"\n            *****"
					"\n           *****~~"
					"\n            **~~~"
					"\n           *~~~***"
					"\n          ~~~******"
					"\n         ~~*********"
					"\n        *************"
					"\n         ***********"
					"\n        *************"
					"\n       ***************"
					"\n      *@***************"
					"\n     ***@************@**"
					"\n    *@****************@**"
					"\n      @****************"
					"\n     *******************"
					"\n    *****@***************"
					"\n   ***********************"
					"\n  ********@****************"
					"\n *****************@*********"
					"\n*****************************"
					"\n            |||||"
					"\n            |||||   _8_8_"
					"\n            |||||  |  |  |_8_"
					"\n            |||||  |__|__|___|";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}