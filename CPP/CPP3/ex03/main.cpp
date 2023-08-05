#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    FragTrap Juan("Juan");

    Juan.attack("Pierre");
    Juan.takeDamage(100);
    Juan.beRepaired(4);
    Juan.takeDamage(3);
    Juan.takeDamage(3);
    Juan.highFivesGuys();


    DiamondTrap	Antoine("Antoine");
	
	Antoine.whoAmI();
	Antoine.attack("Hugo");

    return EXIT_SUCCESS;
}