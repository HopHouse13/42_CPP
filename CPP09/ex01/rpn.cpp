/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pab <pab@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 16:14:28 by pbret             #+#    #+#             */
/*   Updated: 2026/03/11 18:17:37 by pab              ###   ########.fr       */
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

void	Rpn::_handleOperation(char operatorSign)
{
	double	result;

	if (operatorSign == '+')
	{
		result = _values.top();
		_values.pop();
		result += _values.top();
		_values.pop();
		_values.push(result);
	}
	else if (operatorSign == '-')
	{
		result = _values.top();
		_values.pop();
		result -= _values.top();
		_values.pop();
		_values.push(result);
	}
	else if (operatorSign == '*')
	{
		result = _values.top();
		_values.pop();
		result *= _values.top();
		_values.pop();
		_values.push(result);
	}
	else
	{
		result = _values.top();
		_values.pop();
		result /= _values.top();
		_values.pop();
		_values.push(result);
	}
}

int	Rpn::Calculation()
{
	if (_raw.empty())
	{
		std::cout << "Error: input is empty" << std::endl;
		return (FAILLURE);
	}
	int		countV = 0;
	int		countO = 0;
	bool	evenSpace = false;

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
			_values.push(_raw[i] - '0');
		}
		else if (_raw[i] == '+' || _raw[i] == '-' || _raw[i] == '*' || _raw[i] == '/')
			{
				countO++;
				if (_values.size() >= 2)
					_handleOperation(_raw[i]);
			}
		else
		{
			std::cout << "Error: invalid character [" << _raw[i] << "]" << std::endl;
			return (FAILLURE);
		}
	}

	if (countV != (countO + 1) || countV < 2 || countO < 1)
	{
		std::cout << "Error: invalid expression RPN -> operands/operators mismatch" << std::endl;
		return (FAILLURE);
	}

	std::cout << "size: " << _values.size() << "\tresult: " << _values.top() << std::endl;
	return (SUCCESS);
}

