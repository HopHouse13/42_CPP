/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:18 by pbret             #+#    #+#             */
/*   Updated: 2025/12/22 18:59:31 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
	std::cout << "Default constructor of " << this->getNameForm() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Constructor of " << this->getNameForm() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "Copy constructor of " << this->getNameForm() << " called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "Assignment operator of " << this->getNameForm() << " overload called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor of " << this->getNameForm() << " called" << std::endl;
}

void	PresidentialPardonForm::action(void) const
{
	std::cout << CYAN << this->_target << " was pardoned by Zaphod Beeblebrox" << RESET << std::endl;
}
