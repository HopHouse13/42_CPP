/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/12 19:32:48 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie	*zHorde;
	int		nbZommbie = -7;

	if (nbZommbie >= 0 && nbZommbie < INT_MAX)
	{
		zHorde = zombieHorde(nbZommbie, "zHorde");
		for (int i = 0; i < nbZommbie; i++)
			zHorde[i].announce();
		delete [] zHorde;
	}
	else
		std::cout << "invalid value" << std::endl;
	return (0);
}
