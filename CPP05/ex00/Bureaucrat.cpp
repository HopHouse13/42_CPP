/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:41:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/10 19:07:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("unknown"), _grade(0) // grade entre 1 - 150
{
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs)
{
	this->_name = rhs._name;
	this->_grade = rhs._grade;
}
	//Bureaucrat& operator=(const Bureaucrat& rhs);
	//~Bureaucrat(void);
	//const std::string&	getName(void) const;
	//const unsigned int&	getGrade(void) const;
	//void				incrementGrade(void);
	//void				decrementGrade(void);