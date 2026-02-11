/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 17:41:44 by pbret             #+#    #+#             */
/*   Updated: 2026/02/10 15:46:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./easyfind.hpp"

std::list<int>

//std::vector<int>::iterator
template<typename T>
typename T::iterator	easyfind(T const & contener, int const & value)
{
	typename T::const_iterator	it = contener::begin();
}