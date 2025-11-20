/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:16:21 by pbret             #+#    #+#             */
/*   Updated: 2025/11/19 18:13:49 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	remplace(std::string *line, size_t *idx, const std::string *s1, const std::string *s2)
{
	line->erase(*idx, s1->length());							// Dans <line>, supp. a partir de la position <idx> pour la longueur de s1
	line->insert(*idx, *s2);									// Dans <line>, insere s2 a partir de la position <idx> (elle est tjs a la mm pos)
	*idx += s2->length();										// <idx> avant a la position le nombre de char de s2 -> <idx> de line est le char juste apres l'insersion
}

int	handleRemplace(char **av)
{
	std::string		fileName = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	if (s1.empty())												// check si le fichier est vide
		return (2);

	std::ifstream	oldFile(fileName.c_str());					// c_str renvoit un const char * car <std::ifstream> prend un const char *
	if (!oldFile.is_open())										// check si oldFile s'est bien ouvert(check en realite si l'objet oldFine existe)
		return (3);
	//Check fichier d'entree si il est vide
	//Interdire filename/s1 vide
	
	std::string		newF(fileName + ".replace");

	std::ofstream	newFile(newF.c_str());
	if (!newFile.is_open())										// check si newFile s'est correctement ouvert. 
		return (4);

	size_t		idx;
	std::string	line;
	while(getline(oldFile, line))
	{
		idx = 0;
		if (!s1.empty())
		{
			while(((idx = line.find(s1, idx)) != std::string::npos)) // fine renvoie 'std::string::npos' (-1) lorsqu'il n'y a plus d'occurence dans line.
				remplace(&line, &idx, &s1, &s2);
		}
		newFile << line << std::endl;
	}
	oldFile.close();
	newFile.close();											// optionnel : quand on sort du scope de la fonction, le destructeur est appele et ferme automatiquement les file ouverts.
	return (0);
}

int	main(int ac, char **av)
{
	int	err = 1;

	if (ac == 4)
	{
		err = handleRemplace(av);
		if (err == 0)
			std::cout << "The program executed successfully";
		else if (err == 2)
			std::cout << "s1 is empty";
		else if (err == 3)
			std::cout << "Unable to open the input parameter file";
		else if (err == 4)
			std::cout << "Unable to open the new file";
		else
			std::cout << "unknown error";
		std::cout << std::endl;
		return (err);
	}
	std::cout 	<< "The command format is invalid:"
				<< " Please enter the command in the format: ./replace <fileName> <s1> <s2>"
				<< std::endl;
	return (err);
	
}

// est ce que j'enleve la secu si le fichier de dest existe deja? je peux l'ecraser.
// Que faire quand le file d'entree est une dossier???