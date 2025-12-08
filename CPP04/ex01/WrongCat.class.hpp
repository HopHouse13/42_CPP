/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:28:32 by pbret             #+#    #+#             */
/*   Updated: 2025/12/08 14:54:54 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_HPP
# define WRONGCAT_CLASS_HPP

#include "WrongAnimal.class.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(const WrongCat& rhs);
		WrongCat&	operator=(const WrongCat& rhs);
		~WrongCat(void);

		void		makeSound(void) const;
		const std::string&	getType(void) const; // ASUPP

	protected:
		std::string	_type;
};

#endif