/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Flo.class_instance.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:38 by pbret             #+#    #+#             */
/*   Updated: 2025/08/07 19:13:59 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Robot.class.hpp"

Robot::Robot(int buste, int tete, int bras, int jambes) : buste(buste), _tete(tete), _bras(bras), _jambes(jambes)
{
	std::cout << "constructeur called" << std::endl;
	return ;
}

Robot::~Robot()
{
	std::cout << "destructeur called" << std::endl;
	return ;
}

void	Robot::write() const
{
	std::cout << this->buste << std::endl;
	std::cout << this->_tete << std::endl;
	std::cout << this->_bras << std::endl;
	std::cout << this->_jambes << std::endl;
}

// void	Robot::setRobot(int buste, int tete, int bras, int jambres)
// {
// 	if (this->buste >= 0)
// 		Robot::buste =
// }
