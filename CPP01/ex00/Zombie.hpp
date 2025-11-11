/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:01:44 by pbret             #+#    #+#             */
/*   Updated: 2025/11/11 19:01:14 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class	Zombie
{
	public:
		Zombie(std::string name);
		void announce(void);

	private:
		std::string _name;
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);