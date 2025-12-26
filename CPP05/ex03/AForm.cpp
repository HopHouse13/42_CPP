/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:30:36 by pab               #+#    #+#             */
/*   Updated: 2025/12/26 12:51:36 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("unknown"), _isSigned(false), _sigGrade(150), _execGrade(150)
{
	std::cout << "Default constructor of AForm called" << std::endl;
}

AForm::AForm(const std::string name, const unsigned int sigGrade, const unsigned int execGrade)
: _name(name), _isSigned(false)
{
	std::cout << "Constructor of AForm called" << std::endl;
	if (sigGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (sigGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
	this->_sigGrade = sigGrade;
	this->_execGrade = execGrade;
}

AForm::AForm(const AForm& rhs)
: _name(rhs._name), _isSigned(rhs._isSigned), _sigGrade(rhs._sigGrade), _execGrade(rhs._execGrade)
{
	std::cout << "Copy constructor of AForm called" << std::endl;
}

const AForm&	AForm::operator=(const AForm& rhs)
{
	std::cout << "Assignment operator of AForm called" << std::endl;
	if (this != &rhs)
	{
		this->_sigGrade = rhs._sigGrade;
		this->_execGrade = rhs._execGrade;
	}
	return(*this);
}

AForm::~AForm(void)
{
	std::cout << "Destructor of AForm called" << std::endl;
}

const std::string&	AForm::getNameForm(void) const
{
	return(this->_name);
}

const bool&			AForm::getIsSignedForm(void) const
{
	return(this->_isSigned);
}

const unsigned int&	AForm::getSigGradeForm(void) const
{
	return(this->_sigGrade);
}

const unsigned int&	AForm::getExecGradeForm(void) const
{
	return(this->_execGrade);
}

void	AForm::beSigned(const Bureaucrat& guy)
{
	if (this->_sigGrade < guy.getGrade()) // il faut que le bureaucrat soit plus petit que le form pour pouvoir le signer?
		throw AForm::GradeTooHighException();
	this->_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (this->_isSigned == false)
		throw AForm::Unsigned();
	else if (this->_execGrade < executor.getGrade())
		throw AForm::GradeTooHighException();
	else
		action();
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return (RED"The grade of the form is too high\n"RESET);
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return (RED"The grade of the form is too low\n"RESET);
}

const char*	AForm::Unsigned::what(void) const throw()
{
	return (RED"The form is unsigned\n"RESET);
}

std::ostream&	operator<<(std::ostream& outStream, const AForm& rhs)
{
	outStream	<< YELLOW << "The form " << rhs.getNameForm() << std::endl
				<< "Signature grade -> " << rhs.getSigGradeForm() << std::endl
				<< "Execution grade -> " << rhs.getExecGradeForm() << std::endl
				<< "Signature status -> " << rhs.getIsSignedForm() << RESET << std::endl;
	return(outStream);
}