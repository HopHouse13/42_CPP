/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:05 by pbret             #+#    #+#             */
/*   Updated: 2025/08/11 14:16:23 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOT_CLASS_H
# define ROBOT_CLASS_H

#include <iostream>

class	Robot
{
	public :
		Robot(int buste, int tete, int bras, int jambes);
		~Robot();
		int			buste;
		void		write() const;
		void		setRobot(int buste, int tete, int bras, int jambes);
		int			getJambes() const;
		int			getBras() const;
		int			getTete() const;
		int			getBuste() const;
		bool		compareJambes(int jambes) const;
		static int	getNbre_instance();
				
		private :
		int			_bras;
		int 		_jambes;
		int 		_tete;
		static int	_nbr_instance;
};

#endif