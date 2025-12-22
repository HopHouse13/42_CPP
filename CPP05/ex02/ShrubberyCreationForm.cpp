/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:28:18 by pbret             #+#    #+#             */
/*   Updated: 2025/12/22 14:30:20 by pab              ###   ########.fr       */
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

void	ShrubberyCreationForm::action(void) const
{
	std::string	fileName = this->_target + "_shrubbery";
	std::ofstream tree(fileName.c_str());
	if (!tree.is_open())
		throw ShrubberyCreationForm::fileError();
	tree << "\n"
"\n"
"\n"
"               *\n"
"              /|\\\n"
"             /*|O\\\n"
"            /*/|\\*\\\n"
"           /X/0|*\\X\\\n"
"          /*/X/|\\O\\*\\\n"
"         /O/*/X|*\\O\\X\\\n"
"       /*/0/X/*|*\\X\\0\\*\\\n"
"      /X/0/*/X/|\\O\\X\\*\\X\\\n"
"     /*/X/O/X/0|X\\0\\X\\O\\*\\\n"
"   /O/X/*/O/X/*|O\\*\\O\\X\\*\\0\\\n"
"  /*/0/X/*/X/O/|\\*\\O\\X\\0\\X\\*\\\n"
" /X/O/X/0/*/X/O|X\\O\\X\\*\\O\\X\\X\\\n"
"/*/X/O/X/O/X/*/|\\X\\0\\X\\O\\X\\0\\*\\\n"
"             |   |\n"
"             |   |\n"
"        ____/_____\\____\n"
"\n"
"\n"
"\n";
}

const char*	ShrubberyCreationForm::fileError::what(void) const throw()
{
	return (RED"Error creating the tree's file\n"RESET);
}
