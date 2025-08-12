/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:01:05 by pbret             #+#    #+#             */
/*   Updated: 2025/08/11 14:13:47 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Robot.class.hpp"

int	main(void)
{
	Robot	robert(1, 2, 3, 4);
	std::cout << "nombre d'instance : " << Robot::getNbre_instance() << std::endl;
	Robot	magalie(1, 2, 3, 4);
	std::cout << "nombre d'instance : " << Robot::getNbre_instance() << std::endl;
	
	robert.write();
	robert.setRobot(19, 19, 19, 19);
	robert.write();
	std::cout << "on accede a Bras a l'exterieur de la class : " << robert.getBras() << std::endl;
	std::cout << "on accede a jambes a l'exterieur de la class : " << robert.getJambes() << std::endl;
	std::cout << "on accede a tete a l'exterieur de la class : " << robert.getTete() << std::endl;
	std::cout << "on accede a buste a l'exterieur de la class : " << robert.getBuste() << std::endl;
	// std::cout << "value de compareJambes : " << magalie.compareJambes(robert.getJambes()) << std::endl << std::endl;
	if (magalie.compareJambes(robert.getJambes()))
		std::cout << "c'est la meme valeur contre les deux paires de jambes. Sa valeur est " << magalie.getJambes() << std::endl;
	else
		std::cout << " Ce n'est pas la meme paire de jambes!" << std::endl;
	return (0);
}