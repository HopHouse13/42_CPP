/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/23 19:33:10 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{	
	std::cout << "Default constructor of Intern called" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "Copy constructor of Intern called" << std::endl;
	(void)rhs;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	std::cout << "Assignment operator of Intern overload called" << std::endl;
	(void)rhs;
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Destructor of Intern called" << std::endl;
}

AForm*	Intern::makeForm(std::string nameForm, std::string targetForm)
{
	AForm		*ptrForm = NULL;
	std::string	formType[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int			idx = 0;
	
	while (idx < 3)
	{
		if (formType[idx] == nameForm)
			break;
		idx++;
	}
	
	switch (idx)
	{
		case 0:
			ptrForm = new PresidentialPardonForm(targetForm);
			break;
		case 1:
			ptrForm = new RobotomyRequestForm(targetForm);
			break;
		case 2:
			ptrForm = new ShrubberyCreationForm(targetForm);
			break;
		default:
			throw Intern::wrongNameForm();
	}
	return (ptrForm);
}

const char*	Intern::wrongNameForm::what(void) const throw()
{
	return (RED"Invalid form name\n"RESET);
}

