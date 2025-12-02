/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:53:56 by pbret             #+#    #+#             */
/*   Updated: 2025/12/02 14:04:06 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

class ClapTrap
{
	public :
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& src);
		ClapTrap&	operator=(const ClapTrap& rhs);
		~ClapTrap(void);
		
		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string		getName(void) const;
		unsigned int	getHP(void) const;
		unsigned int	getEP(void) const;
		unsigned int	getAttackDmg(void) const;
	
	private :
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_ep;
		unsigned int	_attackDmg;
};

std::ostream&	operator<<(std::ostream& os, const ClapTrap& rhs);

#endif