#include "Erika.class.hpp"
#include <iostream>

Erika::Erika(void)
{
	std::cout << "Constructeur appele" << std::endl;
	return;
}

Erika::~Erika(void)
{
	std::cout << "Deconstructeur appele" << std::endl;
	return;
}