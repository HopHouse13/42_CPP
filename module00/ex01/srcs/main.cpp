/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:22:53 by pbret             #+#    #+#             */
/*   Updated: 2025/08/13 17:53:34 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.class.hpp"
#include "../includes/PhoneBook.class.hpp"

/* 	- rules du programme
	- recuperation commande
	- appel de la bonne fonciton
*/

int	main()
{
	PhoneBook	fpb;
	
	fpb.programRules();
	while (true)
	{
		std::cout << GREEN << "> ";
		if (!std::getline(std::cin, fpb.cmd))
		{
			std::cout << std::endl;
			fpb.messExit();
			break ;
		}
		if (fpb.cmd == "ADD")
			std::cout << "1";
		else if (fpb.cmd == "SEARCH")
			std::cout << "2";
		else if (fpb.cmd == "EXIT")
		{
			if (fpb.exitDoor())
				break;
		}
		else
			fpb.programRules();
	}
	return (0);
}