/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:44:35 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 13:14:43 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

void	randomChump(std::string name)
{
	Zombie	z(name);

	z.announce(); // lorsque la fonction ou l'instance a ete declaree se termine, le destructeur de la class est appele.
}