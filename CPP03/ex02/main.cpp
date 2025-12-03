/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:29:51 by pbret             #+#    #+#             */
/*   Updated: 2025/12/03 17:29:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	std::cout << WHITE << "||| ALIX, GASTON AND PIERRE'S STORY |||" << RESET << std::endl << std::endl;

	FragTrap	Alix("Alix");
	FragTrap	Gaston("Gaston");

	Alix.attack("Gaston");
	Gaston.takeDamage(30);
	Gaston.beRepaired(15);
	Gaston.attack("Alix");
	Alix.takeDamage(30);
	Alix.highFivesGuys();
	Gaston.highFivesGuys();

	FragTrap	Pierre("Pierre");

	Pierre = Pierre;
	Pierre = Alix;
	std::cout << Pierre << std::endl;

	return (0);
}