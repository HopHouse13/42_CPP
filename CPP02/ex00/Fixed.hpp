/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:24:19 by pbret             #+#    #+#             */
/*   Updated: 2025/11/24 16:15:34 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public :
		Fixed();//1) Sinon le compilateur utilise le sien
		Fixed(const Fixed &other); // 3) Copie de la reference other
		Fixed & operator=(const Fixed & rhs);//4) que faire si Fixed b = Fixed a
		~Fixed();//2) Sinon le compilateur utilise le sien
		int		getRawBits() const;
		void	setRawBits(int const raw);

	private:
		int	 				_rawNb; // nombre a virgule 
		int const static 	_bits = 8; // contient la partie decimale en bits (8) (pas sur de tout ca)
};


//class Human
//{
//	private:
//		int _age;
//	public:
//		Human();
//		Human(int age);
//		Human(const Human &copy);
//		Human &operator=(const Human &rhs);
//		~Human();
//};

//Human::Human() : _age(0)
//{
//}

//Human::Human(int age) : _age(age)
//{
//}

//Human::Human(const Human &copy) : _age(copy._age)
//{
//}

//Human &Human::operator=(const Human &rhs)
//{
//	if (this != &rhs)
//	{
//		_age = rhs._age;
//	}
//	return (*this);
//}

//Human::~Human()
//{
//}

#endif 