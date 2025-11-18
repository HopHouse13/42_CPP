/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:39 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 17:09:18 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include "Weapon.class.hpp"
#include <string>

class	HumanA
{
	public:
		HumanA(std::string const &name, Weapon const& weapon);
		~HumanA(void);
		void		attack(void);

	private:	
		std::string	_name;
		Weapon const& _weapon;
};
#endif