/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:19:58 by pbret             #+#    #+#             */
/*   Updated: 2026/01/24 18:17:52 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

//#include "./empty.class.hpp"

#include <iostream>

class Base
{
	public:
		virtual ~Base();
};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif