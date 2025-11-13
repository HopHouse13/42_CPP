/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:39 by pbret             #+#    #+#             */
/*   Updated: 2025/11/13 19:14:55 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class	HumanA
{
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void		attack(void);

	private:
		Weapon		&_Weapon;
		std::string	_name;
};
#endif