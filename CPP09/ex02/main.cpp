/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:00:17 by pbret             #+#    #+#             */
/*   Updated: 2026/03/19 17:00:55 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeCommon.hpp"
#include "./PmergeMeDeque.hpp"

int	main(int ac, char **av)
{
	if (ac <= 2)
	{
		if (ac < 2)
			std::cerr << "Error: no input provided. Please enter a sequence of elements." << std::endl;
		else
			std::cerr << "Error: at least two elements are required to sort." << std::endl;
		return (1);
	}

	if (parsing(av) == false)
		std::cerr << "Error: invalid input. All elements must be positive integers." << std::endl;

	SortDeque	SortDeque;
	SortDeque.handleSortDeque(av, ac);

	//SortVector	SortVector;
	//SortVector.handleSortVector(av, ac);

	return (0);
}

// roadmap:

// - parsing -> only digits positifs
// - init. _main
// - cb de niveau de recurtion : compter cb de valeur + cb de niveau de profondeur en doublant le bn de valeurs dans les paires a chaque niveau de recurtion
// - affichage du main avant le sort