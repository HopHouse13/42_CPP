/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/13 19:44:44 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

int	main()
{
	// Humain A est oublige d'avoir une arme -> il doit prendre une REF en 2eme arg
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club); // club est une instance de type Weapon ok mais le constructeur HumanA prends une REF. Je comprends pas

	bob.attack();
	club.setType("some other type of club");
	bob.attack();

	//Weapon club = Weapon("crude spiked club");
	//HumanB jim("Jim");

	//jim.setWeapon(club);
	//jim.attack();
	//club.setType("some other type of club");
	//jim.attack();
	return 0;
}
