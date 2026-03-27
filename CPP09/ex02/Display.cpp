/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:55:16 by pbret             #+#    #+#             */
/*   Updated: 2026/03/27 15:56:11 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

std::ostream& operator<<(std::ostream& os, std::deque<int> const & list) // operateur de surcharge sur << et avec le flux std::cout
{
	for (size_t i = 0; i < list.size(); i++)
		os << (i ? " " : "") << list.at(i);
	return (os);
}

//std::ostream& operator<<(std::ostream& os, std::deque<SortDeque::Elem> const & d);
