/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:06:37 by pbret             #+#    #+#             */
/*   Updated: 2026/03/11 18:12:42 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rpn.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: RPN must take exactly one argument" << std::endl;
		return (1);
	}

	Rpn	rpn(av[1]);
	rpn.Calculation();
	
	return (0);
}