/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:26 by pbret             #+#    #+#             */
/*   Updated: 2026/04/01 15:52:19 by pab              ###   ########.fr       */
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

std::deque<unsigned long long> const	initErnstJacobsthal(size_t nbValue)
{
	std::deque<unsigned long long>	suitJ;

	if (nbValue == 0)
		return (suitJ);
	suitJ.push_back(3);
	if (nbValue == 1)
		return (suitJ);
	suitJ.push_back(5);
	for (size_t i = 2; i < nbValue; ++i)
	{
		unsigned long long	prev2 = suitJ[i - 2];
		unsigned long long	prev1 = suitJ[i - 1];

		if (prev2 > (std::numeric_limits<unsigned long long>::max() - prev1) / 2) // check si le resultat de prev2 * 2 + prev1 ne depasse pas le max de unsigned long long
		{
			std::cerr << "Warning: Jacobsthal generation stopped to avoid overflow" << std::endl;
			break ;
		}
		suitJ.push_back(prev2 * 2 + prev1);
	}
	return (suitJ);
}
