/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:39 by pbret             #+#    #+#             */
/*   Updated: 2025/11/18 16:13:14 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string const &type);
		~Weapon(void);
		const	std::string &getType(void) const;
		void	setType(std::string type);

	private:
		std::string	_type;
};

#endif