/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:19:27 by pbret             #+#    #+#             */
/*   Updated: 2025/08/12 14:19:30 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream> // std::cout/endl

// toupper renvoit la valeur decimale ascii, il faut la cast en char.
void	to_upper(int argc, char **argv)
{
	int		i = 0;
	int		j = -1;

	while(argv[++i])
	{
		j = -1;
		while (argv[i][++j])
			std::cout << (char)std::toupper(argv[i][j]);
		if (i != argc - 1)
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		to_upper(argc, argv);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}