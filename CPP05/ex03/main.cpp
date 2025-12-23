/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:56:19 by pbret             #+#    #+#             */
/*   Updated: 2025/12/23 19:44:03 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		std::cout << YELLOW << "/// Forms valids ///" << RESET << std::endl;
		Intern	Alix;
		Bureaucrat Paul("Paul", 1);
		
		AForm*	f1 = Alix.makeForm("PresidentialPardonForm", "Pab");
		Paul.signForm(*f1); // dereferencement car il faut une ref. et pas une adresse
		Paul.executeForm(*f1);
		AForm*	f2 = Intern().makeForm("RobotomyRequestForm", "Pab"); // instance temporaire: son scope est uniquement aur la ligne
		Paul.signForm(*f2);
		Paul.executeForm(*f2);
		AForm*	f3 = Alix.makeForm("ShrubberyCreationForm", "Pab");
		Paul.signForm(*f3);
		Paul.executeForm(*f3);	
		delete (f1); // delete des form car l'initilisation est dynamique (new)
		delete (f2);
		delete (f3);

		std::cout << YELLOW << "/// Form invalid ///" << RESET << std::endl;
		Intern	sundae;
		Bureaucrat Flan("Flan", 1);
		
		AForm*	f4 = sundae.makeForm("WrongNameForm", "Pab"); // name invalid
		Flan.signForm(*f4); // code pas exec car un throw a ete envoye la ligne au dessus
		Flan.executeForm(*f4);
		delete (f4);
	}
	catch (std::exception& excep)
	{
		std::cerr << excep.what();
	}
	return (0);
}
