/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 17:19:58 by pbret             #+#    #+#             */
/*   Updated: 2026/01/26 15:26:13 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_HPP
# define BASE_CLASS_HPP

#include <iostream>
#include <ctime> // time
#include <cstdlib> // rand()

class Base
{
	public:
		virtual ~Base();
};

Base*	generate();
void	identify(Base* p);
void	identify(Base& p);

#endif