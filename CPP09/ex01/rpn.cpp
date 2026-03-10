/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:28 by pbret             #+#    #+#             */
/*   Updated: 2026/03/10 19:10:40 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rpn.hpp"

Rpn::Rpn()
{
	std::cout << "Default constructor called" << std::endl;
}

Rpn::Rpn(std::string const raw) : _raw(raw)
{
	std::cout << "Default constructor called" << std::endl;
}

Rpn::~Rpn()
{
	std::cout << "Destructor called" << std::endl;
}

Rpn::Rpn(Rpn const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_values = copy._values;
}

Rpn & Rpn::operator=(Rpn const & rhs)
{
	std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
		this->_values = rhs._values;
	return (*this);
}

////////////////////////////////////////////////////////////////////////

int	Rpn::parse()
{
	if (_raw.empty())
	{
		std::cout << "Error: input is empty" << std::endl;
		return (FAILLURE);
	}
	int		countV = 0;
	int		countO = 0;
	bool	even = 0;
// a refaire la logique de l' espace
	if (_raw[0] == ' ')
		

	for (int i = 0; i < static_cast<int>(_raw.size()); i++) // size renvoit un size_t
	{
		//if (_raw[i] == ' ')
		//{
		//	if (even == -1)
		//		even = i % 2;
		//	else if (i % 2 != even)
		//	{
		//		std::cout << "Error: invalid input -> consecutive spaces are not allowed" << std::endl;
		//		return (FAILLURE);
		//	}
		//	continue;
		}
		else if (_raw[i] >= '0' && _raw[i] <= '9')
		{
			countV++;
			_values.push(_raw[i] - 48);
		}
		else if (_raw[i] == '+' || _raw[i] == '-' || _raw[i] == '*' || _raw[i] == '/')
			countO++;
		else
		{
			std::cout << "Error: invalid character [" << _raw[i] << "]" << std::endl;
			return (FAILLURE);
		}
	}
	return (SUCCESS);
}

void	Rpn::calculate()
{
	if (parse() == FAILLURE)
		std::cout << "TEST\n";
}
