#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap	Thib("Thib");

    Thib.attack("Vinc");

    FragTrap Juan("Juan");

    Juan.attack("Pierre");
    Juan.takeDamage(100);
    Juan.beRepaired(4);
    Juan.takeDamage(3);
    Juan.takeDamage(3);
    Juan.highFivesGuys();

	ScavTrap	Francois("Francois");

    Juan.attack("Pierre");
    Juan.takeDamage(100);
    Juan.beRepaired(4);
    Juan.takeDamage(3);
    Juan.takeDamage(3);

    return EXIT_SUCCESS;
}