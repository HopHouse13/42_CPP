/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/16 16:37:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150)
{	
	std::cout << "Default constructor of " << this->_name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade) : _name(name)
{	
	std::cout << "Constructor of " << this->_name << " called" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException(); // c'est quoi exactement? un constructeur?
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade)
{
	std::cout << "Copy constructor of " << this->_name << " called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Assignment operator of " << this->_name << " overload called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor of " << this->_name << " called" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (this->_name);
}

const unsigned int&	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED"Grade is too high\n"RESET); // est ce que cela va a l'encontre du sujet "\n"?
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED"Grade is too low\n"RESET);
}

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& rhs)
{
	outStream << YELLOW << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
	return (outStream);
}