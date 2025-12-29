/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/29 16:18:20 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::cout << YELLOW << "/// Invalid cases ///" << RESET << std::endl;

	try
	{
		Bureaucrat				b1("b1", 150);
		ShrubberyCreationForm	f1("jardin"); // (sigGrade 145, execGrade 137)

		b1.signForm(f1); // b1.grade(150) > f1.sigGrade(145) -> grade de b1 est trop low
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat			b2("b2", 1);
		RobotomyRequestForm	f2("Harry");

		b2.executeForm(f2); // f2 n'est pas signe
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}

	try
	{
		Bureaucrat				b3("b3", 20);
		PresidentialPardonForm	f3("Harry"); // (sigGrade 25, execGrade 5)

		b3.signForm(f3);
		b3.executeForm(f3);  // b3.grade(20) > f1.sigGrade(5) -> grade de b3 est trop low
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	std::cout << YELLOW << "/// Valid cases ///" << RESET << std::endl;

	Bureaucrat	b4("b4", 1);
	try
	{
		ShrubberyCreationForm	f4("jardin");

		b4.signForm(f4);
		b4.executeForm(f4);

		RobotomyRequestForm	f5("Harry");

		b4.signForm(f5);
		b4.executeForm(f5);

		PresidentialPardonForm	f6("Harry");

		b4.signForm(f6);
		b4.executeForm(f6);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	return (0);
}
