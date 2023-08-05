#include <iostream>
#include <limits>
#include "Zombie.hpp"

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int	main(void)
{
	int N = 10;

	Zombie	*z = zombieHorde(N, "Juan");
	for (int i = 0; i < N; i++) {
		z[i].announce();
	}
	delete[] z;
    
	return(0);
}