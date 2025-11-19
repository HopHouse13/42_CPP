/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 13:34:20 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 15:32:26 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{

	if (ac == 2)
	{
		Harl	Harl;

		Harl.complain(av[1]);
	}
	else
	{
		std::cout 	<< "The command format is invalid:"
					<< " Please enter the command in the format <./HarlFilter> <level>" << std::endl
					<< "level available : <DEBUG> <INFO> <WARNING> <ERROR>" << std::endl;
		return (1);
	}
	return (0);
}
