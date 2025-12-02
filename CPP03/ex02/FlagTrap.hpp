/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:07:23 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 19:11:22 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{
	public :
		FlagTrap();
		FlagTrap(const std::string& name);
		FlagTrap(const FlagTrap& src);
		FlagTrap& operator=(const FlagTrap& rhs);
		~FlagTrap();

		void	highFivesGuys(void);
};
#endif