/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/22 19:08:11 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Flo("Flo", 21);
		Bureaucrat Pab("Pab", 2);
		std::cout << Flo;
		std::cout << Pab;

		ShrubberyCreationForm	F1("Maison");
		RobotomyRequestForm		F2("Sundae");
		PresidentialPardonForm	F3("Phillippe Morris");

		
		std::cout << F1;
		Pab.signForm(F1);
		Flo.execteForm(F1);

		std::cout << F2;
		Pab.execteForm(F2);
		Flo.signForm(F2);
		Pab.execteForm(F2);

		std::cout << F3;
		Flo.signForm(F3);
		Flo.execteForm(F3);
		Pab.execteForm(F3);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	return (0);
}
