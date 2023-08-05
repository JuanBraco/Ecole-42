#include <iostream>
#include <limits>
#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int	main(void)
{

	Zombie	*z = newZombie("Juan");
	z->announce();
	randomChump("Eric");
	delete z;

    return(0);
}