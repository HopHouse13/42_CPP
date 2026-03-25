/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:54 by pbret             #+#    #+#             */
/*   Updated: 2026/03/25 14:40:29 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMECOMMON_HPP
# define PMERGEMECOMMON_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <cmath>

# define SUCCESS 0
# define FAILURE 1

bool	parsing(char ** av);
int		depthCount(int nbElem);
//void	initErnstJaceobsthal();

#endif