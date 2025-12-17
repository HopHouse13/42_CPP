/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:18 by pbret             #+#    #+#             */
/*   Updated: 2025/12/17 17:43:30 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
	std::cout << "Default constructor of " << this->getNameForm() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Constructor of " << this->getNameForm() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "Copy constructor of " << this->getNameForm() << " called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "Assignment operator of " << this->getNameForm() << " overload called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destructor of " << this->getNameForm() << " called" << std::endl;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	if ()
}
