/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:01:44 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 19:42:30 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
		void	setName(std::string name);
	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif
