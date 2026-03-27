/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:26 by pbret             #+#    #+#             */
/*   Updated: 2026/03/27 19:38:58 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMeCommon.hpp"

// check si digits positifs
// check int_max
bool	parsing(char ** av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return(false);
		}
		if (std::atof(av[i]) > std::numeric_limits<int>::max()) // conversion en double pour check le int_max
			return (false);
	}
	return (true);
}

int	depthCount(int nbElem)
{
	if (nbElem % 2 != 0) // passe ne nb d'elements pair si il etait impair
		nbElem--;

	int	lvl = 0;
	
	while (nbElem >= 2)
	{
		nbElem /= 2;
		lvl++;
	}
	return (lvl);
}

std::deque<double> const	initErnstJacobsthal(int nbValue)
{
	std::deque<double>	suitEJ;

	if (nbValue == 0)
		return (suitEJ);
	suitEJ.push_back(0);
	if (nbValue == 1)
		return (suitEJ);
	suitEJ.push_back(1);
	for (double i = 2;  i < nbValue; i++)
		suitEJ.push_back(suitEJ[i - 2] * 2 + suitEJ[i - 1]);

	for (double i = 0; i < suitEJ.size(); i++)
		std::cout << std::fixed << std::setprecision(0) << suitEJ[i] << std::endl;
	return (suitEJ);
}

