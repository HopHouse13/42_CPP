/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:18 by pbret             #+#    #+#             */
/*   Updated: 2025/12/23 17:18:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("unknown")
{
	std::cout << "Default constructor of " << this->getNameForm() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Constructor of " << this->getNameForm() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << "Copy constructor of " << this->getNameForm() << " called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "Assignment operator of " << this->getNameForm() << " overload called" << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor of " << this->getNameForm() << " called" << std::endl;
}

void	RobotomyRequestForm::action(void) const
{
	srand(time(NULL)); // srand reinitialiser un generateur de valeurs. Si aucune valeur donnee, le generateur est initialise toujours de la meme maniere. Si une valeur est apportee, le generateur est reinitialiser avec une nouvelle seed basee sur cette valeur. Time(NULL) donne l'heure en sec donc une valeur toujours differente.  
	
	std::cout << CYAN;
	if (rand() % 2) // rand foncitonne avec srand, il revoit la valeur generee.
		std::cout << "\"#($*ˆ%#(*%@)&*$ˆ%)*$!!!\" *DRILL NOISE* " << this->_target << " was robotomized" << std::endl;
	else
		std::cout << this->_target << " was not robotomized" << std::endl;
	std::cout << RESET;
}
