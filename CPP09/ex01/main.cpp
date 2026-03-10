/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:06:37 by pbret             #+#    #+#             */
/*   Updated: 2026/03/10 18:13:43 by pbret            ###   ########.fr       */
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
	rpn.calculate();
	return (0);
}