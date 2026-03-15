/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:28 by pbret             #+#    #+#             */
/*   Updated: 2026/03/15 16:53:37 by pab              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rpn.hpp"

Rpn::Rpn()
{
	// std::cout << "Default constructor called" << std::endl;
}

Rpn::Rpn(std::string const raw) : _raw(raw)
{
	// std::cout << "Default constructor called" << std::endl;
}

Rpn::~Rpn()
{
	// std::cout << "Destructor called" << std::endl;
}

Rpn::Rpn(Rpn const & copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->_stackValues = copy._stackValues;
	this->_raw = copy._raw;
}

Rpn & Rpn::operator=(Rpn const & rhs)
{
	// std::cout << "Assignment operator overload called" << std::endl;
	if (this != &rhs)
	{
		this->_stackValues = rhs._stackValues;
		this->_raw = rhs._raw;
	}
	return (*this);
}

////////////////////////////////////////////////////////////////////////

int	Rpn::_handleOperation(char operatorSign)
{
	double	value1;
	double	value2;

	if (operatorSign == '+')
	{
		value2 = _stackValues.top();
		_stackValues.pop();
		value1 = _stackValues.top();
		_stackValues.pop();
		_stackValues.push(value1 + value2);
	}
	else if (operatorSign == '-')
	{
		value2 = _stackValues.top();
		_stackValues.pop();
		value1 = _stackValues.top();
		_stackValues.pop();
		_stackValues.push(value1 - value2);
	}
	else if (operatorSign == '*')
	{
		value2 = _stackValues.top();
		_stackValues.pop();
		value1 = _stackValues.top();
		_stackValues.pop();
		_stackValues.push(value1 * value2);
	}
	else
	{
		value2 = _stackValues.top();
		_stackValues.pop();
		value1 = _stackValues.top();
		_stackValues.pop();
		if (/*value1 == 0 ||*/ value2 == 0) // (0 / 2) = 0 ; (2 / 0) = inf
			return (FAILLURE);
		_stackValues.push(value1 / value2);
	}
	return (SUCCESS);
}

int	Rpn::Calculation()
{
	int		countV = 0;
	int		countO = 0;
	bool	evenSpace = false;

	if (_raw.empty() || _raw.find_first_not_of(' ') == std::string::npos)
	{
		std::cout << "Error: input is empty" << std::endl;
		return (FAILLURE);
	}
	
	if (_raw[0] == ' ')
		evenSpace = true;
	for (int i = 0; i < static_cast<int>(_raw.size()); i++) // size renvoit un size_t
	{
		if (_raw[i] == ' ')
		{
			if ((evenSpace == true && i % 2 != 0) || (evenSpace == false && i % 2 != 1))
			{
				std::cout << "Error: invalid input -> consecutive spaces are not allowed" << std::endl;
				return (FAILLURE);
			}
			continue ;
		}
		if (_raw[i] != ' ' && ((evenSpace == true && i % 2 == 0) || (evenSpace == false && i % 2 == 1)))
		{
			std::cout << "Error: invalid input -> consecutive operands/operators are not allowed" << std::endl;
			return (FAILLURE);
		}

		if (_raw[i] >= '0' && _raw[i] <= '9')
		{
			countV++;
			_stackValues.push(_raw[i] - '0');
		}
		else if (_raw[i] == '+' || _raw[i] == '-' || _raw[i] == '*' || _raw[i] == '/')
		{
			countO++;
			if (countV < 2 || countO >= countV)
			{
				std::cout << "Error: invalid expression RPN -> operands/operators mismatch" << std::endl;
				return (FAILLURE);
			}	
			if (_handleOperation(_raw[i]) == FAILLURE)
			{
				std::cout << "Error: cannot divide by zero" << std::endl;
				return (FAILLURE);
			}
			countV--; // car 2 valeurs sont brulées mais une valeur est creée (le resultat de l'operation) 
			countO--;
		}
		else
		{
			std::cout << "Error: invalid character [" << _raw[i] << "]" << std::endl;
			return (FAILLURE);
		}
	}

	if (_stackValues.size() > 1 || countO > 0)
	{
		std::cout << "Error: invalid expression RPN -> operands/operators mismatch" << std::endl;
		return (FAILLURE);
	}

	std::cout << "result: " << _stackValues.top() << std::endl;
	return (SUCCESS);
}

