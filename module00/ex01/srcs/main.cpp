/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:22:53 by pbret             #+#    #+#             */
/*   Updated: 2025/08/19 01:41:02 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

/* 	- rules du programme
	- recuperation commande
	- appel de la bonne fonciton
*/

int	main()
{
	PhoneBook	fpb;

	while (true)
	{
		fpb.programRules();
		std::cout << WHITE << "> ";
		if (!std::getline(std::cin, fpb.cmd)
			|| (fpb.cmd == "EXIT" && !fpb.exitCmd()))
			break ;
		else if (fpb.cmd == "ADD")
		{	
			if (!fpb.addCmd())
				break ;
		}
		else if (fpb.cmd == "SEARCH")
		{	
			if (!fpb.searchCmd())
				break ;
		}
		else
			std::cout << GOLD << "Invalid input. try again." << std::endl;
	}
	fpb.exitMess();
	return (0);
}