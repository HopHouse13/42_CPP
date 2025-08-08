/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:05 by pbret             #+#    #+#             */
/*   Updated: 2025/08/08 19:19:29 by pbret            ###   ########.fr       */
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
		int		buste;
		void	write() const;
		void		setRobot(int buste, int tete, int bras, int jambes);
		
	private :
		int		_bras;
		int 	_jambes;
		int 	_tete;
};

#endif