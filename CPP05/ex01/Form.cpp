/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:30:36 by pab               #+#    #+#             */
/*   Updated: 2025/12/15 21:44:09 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("unknown"), _isSigned(false), _sigGrade(150), _execGrade(150)
{
	std::cout << "Default construtor of " << this->_name << " called" << std::endl;
}

Form::Form(const std::string name, const unsigned int sigGrade, const unsigned int execGrade)
: _name(name), _isSigned(false)
{
	std::cout << "Construtor of " << this->_name << " called" << std::endl;
	if (sigGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (sigGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	this->_sigGrade = sigGrade;
	this->_execGrade = execGrade;
}

Form::Form(const Form& rhs)
: _name(rhs._name), _isSigned(rhs._isSigned), _sigGrade(rhs._sigGrade), _execGrade(rhs._execGrade)
{
	std::cout << "Copy construtor of " << this->_name << " called" << std::endl;
}
const Form&	Form::operator=(const Form& rhs)
{
	std::cout << "Assignment operator of " << this->_name << " overload called" << std::endl;
	if (this != &rhs)
	{
		//this->_name = rhs._name; // ATTENTION sujet demande un const mais dans l'operateur d'affection nous ne pouvons pas initialiser _name.
		this->_sigGrade = rhs._sigGrade;
		this->_execGrade = rhs._execGrade;
	}
	return(*this);
}

Form::~Form(void)
{
	std::cout << "Destrutor of " << this->_name << " called" << std::endl;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return (RED"The grade of the form is too high\n"RESET);
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return (RED"The grade of the form is too low\n"RESET);
}

const bool& Form::getIsSigned(void) // aSUPP
{
	return (this->_isSigned);
}