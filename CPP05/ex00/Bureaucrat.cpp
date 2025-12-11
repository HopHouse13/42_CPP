/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/11 19:09:12 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(150) // grade entre 1 - 150
{	
	std::cout << "Default constructor of " << this->_name << " called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const unsigned int grade) : _name(name)
{	
	std::cout << "Constructor of " << this->_name << " called" << std::endl;
	try
	{
		if(grade < 1)
			throw Bureaucrat::GradeTooLowException(); // c'est quoi exactement? un constructeur?
		if(grade > 150)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what();
	}
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
	{
		this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
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
	this->_grade++;
}

void	Bureaucrat::decrementGrade(void)
{
	this->_grade--;
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return(RED"Grade is too high\n"RESET);
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return(RED"Grade is too low\n"RESET);
}

std::ostream&	operator<<(std::ostream& outStream, const Bureaucrat& rhs)
{
	outStream << YELLOW << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << RESET << std::endl;
	return (outStream);
}