/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:22:53 by pbret             #+#    #+#             */
/*   Updated: 2025/08/15 10:10:52 by pbret            ###   ########.fr       */
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

	fpb.programRules();
	while (true)
	{
		std::cout << WHITE << "> ";
		if (!std::getline(std::cin, fpb.cmd)
			|| (fpb.cmd == "EXIT" && fpb.exitCmd()))
		{
			fpb.exitMess();
			break ;
		}
		if (fpb.cmd == "ADD")
			fpb.addCmd();
		else if (fpb.cmd == "SEARCH")
			fpb.searchCmd();
		else
			fpb.programRules();
	}
	return (0);
}