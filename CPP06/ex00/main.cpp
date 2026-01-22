/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:30:57 by pbret             #+#    #+#             */
/*   Updated: 2026/01/22 18:18:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: The input parameter must be in the following format ./convert <param>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
