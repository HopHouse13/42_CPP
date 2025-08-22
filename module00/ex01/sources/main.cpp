/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:22:53 by pbret             #+#    #+#             */
/*   Updated: 2025/08/22 12:00:53 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.class.hpp"

int	main()
{
	PhoneBook	fpb;

	while (true)
	{
		fpb.programRules();
		std::cout << WHITE << "> ";
		if (!std::getline(std::cin, fpb.cmd))
			break ;
		if (fpb.cmd == "EXIT")
		{
			if (fpb.exitCmd())
				continue ;
			break ;
		}
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
	return (0);
}
