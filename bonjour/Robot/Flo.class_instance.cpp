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

Robot::Robot(int buste, int bras, int jambes, int tete) : buste(buste), _bras(bras), _jambes(jambes), _tete(tete)
{
	std::cout << "constructeur called" << std::endl;
	Robot::_nbr_instance++;
	return ;
}

Robot::~Robot()
{
	std::cout << "destructeur called" << std::endl;
	Robot::_nbr_instance--;
	return ;
}

void	Robot::write() const
{
	std::cout << this->buste << std::endl;
	std::cout << this->_tete << std::endl;
	std::cout << this->_bras << std::endl;
	std::cout << this->_jambes << std::endl;
}

void	Robot::setRobot(int buste, int tete, int bras, int jambes)
{
		Robot::buste = buste;
		this->_tete = tete;
		this->_bras = bras;
		this->_jambes = jambes;
}

int	Robot::getJambes() const
{
	return (this->_jambes);
}

int	Robot::getBras() const
{
	return (this->_bras);
}

int	Robot::getTete() const
{
	return (this->_tete);
}

int	Robot::getBuste() const
{
	return (this->buste);
}

bool	Robot::compareJambes(int jambes) const
{
	std::cout << "value jambes M : " << jambes << std::endl;
	std::cout << "value jambes R : " << Robot::_jambes << std::endl;
	if (jambes == Robot::_jambes)
		return (1);
	return (0);
}

int	Robot::getNbre_instance()
{
	return (Robot::_nbr_instance);
}

int Robot::_nbr_instance = 0;