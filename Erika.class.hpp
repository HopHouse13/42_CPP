/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Erika.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:05 by pbret             #+#    #+#             */
/*   Updated: 2025/08/07 19:13:37 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERIKA_CLASS_H
# define ERIKA_CLASS_H

#include <iostream> // gestion entree/sortie (i -> in, o -> out, stream -> flux)
# include <string> // gestion des string

class Erika
{
	public:
	
		Erika(char alix1, int alix2 ,float alix3, std::string alix4);
		~Erika(void);
		char		seb1;
		int			seb2;
		float		seb3;
		std::string	seb4; // string
		void	ft_write(void) const;
};

#endif