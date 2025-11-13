/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:11:39 by pbret             #+#    #+#             */
/*   Updated: 2025/11/13 19:31:07 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon(void);
		const	std::string &getType(void);
		void	setType(std::string type);

	private:
		std::string	_type;
};
