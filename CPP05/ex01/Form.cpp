/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 19:30:36 by pab               #+#    #+#             */
/*   Updated: 2025/12/29 16:12:38 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("unknown"), _isSigned(false), _sigGrade(150), _execGrade(150)
{
	std::cout << "Default constructor of " << this->_name << " called" << std::endl;
}

Form::Form(const std::string name, const int sigGrade, const int execGrade)
: _name(name), _isSigned(false) , _sigGrade(sigGrade), _execGrade(execGrade)
{
	std::cout << "Constructor of " << this->_name << " called" << std::endl;
	if (sigGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (sigGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs)
: _name(rhs._name), _isSigned(rhs._isSigned), _sigGrade(rhs._sigGrade), _execGrade(rhs._execGrade)
{
	std::cout << "Copy constructor of " << this->_name << " called" << std::endl;
}

const Form&	Form::operator=(const Form& rhs)
{
	std::cout << "Assignment operator of " << this->_name << " overload called" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return(*this);
}

Form::~Form(void)
{
	std::cout << "Destructor of " << this->_name << " called" << std::endl;
}

const std::string&	Form::getNameForm(void) const
{
	return(this->_name);
}

const bool&			Form::getIsSignedForm(void) const
{
	return(this->_isSigned);
}

const int&	Form::getSigGradeForm(void) const
{
	return(this->_sigGrade);
}

const int&	Form::getExecGradeForm(void) const
{
	return(this->_execGrade);
}

void	Form::beSigned(const Bureaucrat& guy)
{
	if (this->_sigGrade < guy.getGrade())
		throw Form::GradeTooHighException();
	this->_isSigned = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return (RED"The grade of the form is too high\n"RESET);
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return (RED"The grade of the form is too low\n"RESET);
}

std::ostream&	operator<<(std::ostream& outStream, const Form& rhs)
{
	outStream	<< YELLOW << "The form " << rhs.getNameForm() << ":" << std::endl
				<< "Signature grade -> " << rhs.getSigGradeForm() << std::endl
				<< "Execution grade -> " << rhs.getExecGradeForm() << std::endl
				<< "Signature status -> " << rhs.getIsSignedForm() << RESET << std::endl;
	return(outStream);
}