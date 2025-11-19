/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:50:17 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 14:33:11 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zHorde; // ptr du futur tab de zombie

	zHorde = new Zombie[N]; // allocation du tab

	for (int i = 0; i < N; i++)
		zHorde[i].setName(name); // set le name pour chaque zombie
		
	return (zHorde); // retour ptr du tab
}