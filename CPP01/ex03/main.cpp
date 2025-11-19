/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 15:13:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon Weapon1 = Weapon("a baseball bat");
	HumanA bob("Bob", Weapon1);

	bob.attack();
	Weapon1.setType("an iron bar");
	bob.attack();

	std::cout << "-----------" << std::endl;
	
	Weapon Weapon2 = Weapon("a toothbrush");
	HumanB jim("Jim");

	jim.attack();
	jim.setWeapon(Weapon2);
	jim.attack();
	Weapon2.setType("a broom"); //balai
	jim.attack();
	return (0);
}

//Weapon club1("weapon1"); //Stack
//Weapon club2 = Weapon("weapon2"); //Stack
//Weapon *club3 = new Weapon("weapon3"); //Heap