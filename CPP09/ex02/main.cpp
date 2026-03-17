/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:17 by pbret             #+#    #+#             */
/*   Updated: 2026/03/17 17:43:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		if (ac < 2)
			std::cerr << "Error: missing input: ./PmergeMe <positive integers>" << std::endl;
		else
			std::cerr << "Error: at least two positive integers are required to sort" << std::endl;
		return (1);
	}

	SortDeque	SortDeque;
	SortDeque.handleSort(av, ac);

	//SortVector	SortVector;
	//SortVector.handleSort(av, ac);

	return (0);
}
