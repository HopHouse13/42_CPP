/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:03:33 by pbret             #+#    #+#             */
/*   Updated: 2025/12/05 18:31:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include "Animal.class.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& rhs);
		Cat&		operator=(const Cat& rhs);
		~Cat(void);

		void		makeSound(void) const;

	protected:
		std::string	_type;
};

#endif