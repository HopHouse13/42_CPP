/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:37:00 by pbret             #+#    #+#             */
/*   Updated: 2026/02/21 17:08:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>
# include <algorithm>

# include <list>
# include <vector>


template<typename T>
typename T::const_iterator	easyfind(T const & container, int const & value); // typename signifie que 'T:const_iterator'est bien le type de retour (un iterator d'un contener de type primitif)

# include "easyfind.tpp"

#endif