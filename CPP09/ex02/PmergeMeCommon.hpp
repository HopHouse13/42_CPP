/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:54 by pbret             #+#    #+#             */
/*   Updated: 2026/03/29 18:53:46 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMECOMMON_HPP
# define PMERGEMECOMMON_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>
# include <iterator>

# include "./PmergeMeDeque.hpp"
# include "./PmergeMeVector.hpp"

# define SUCCESS 0
# define FAILURE 1

bool	parsing(char ** av);
int		depthCount(int nbElem);
std::deque<unsigned long long> const	initErnstJacobsthal(size_t nbValue);

#endif