/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeCommon.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 15:37:54 by pbret             #+#    #+#             */
/*   Updated: 2026/03/20 12:00:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEMECOMMON_HPP
# define PMERGEMECOMMON_HPP

# include <iostream>
# include <cstdlib>

# define SUCCESS 0
# define FAILURE 1

bool	parsing(char ** av);

int		depth(char ** av);
#endif