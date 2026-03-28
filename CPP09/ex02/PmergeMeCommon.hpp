/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:54 by pbret             #+#    #+#             */
/*   Updated: 2026/03/28 10:52:59 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMECOMMON_HPP
# define PMERGEMECOMMON_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <cmath>
# include <iomanip>

# include "./PmergeMeDeque.hpp"
# include "./PmergeMeVector.hpp"

bool	parsing(char ** av);
int		depthCount(int nbElem);
std::deque<unsigned long long> const	initErnstJacobsthal(size_t nbValue);

#endif