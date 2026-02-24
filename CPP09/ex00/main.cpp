/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:48:39 by pbret             #+#    #+#             */
/*   Updated: 2026/02/24 19:30:25 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

int	main(int ac, char ** av)
{
	if (ac != 2)
	{
		std::cout << "FAILURE: le programme prend un seul argument d'entree" << std::endl;
		return (FAILURE);
	}
	btcExchange	objBts;
	std::string input(av[1]);

	objBts.btcCalculate(input);

	
	return (0);
}