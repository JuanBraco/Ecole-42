#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ScavTrap Juan("Juan");

    Juan.attack("Pierre");
    Juan.takeDamage(100);
    Juan.beRepaired(4);
    Juan.takeDamage(3);
    Juan.takeDamage(3);
    Juan.guardGate();

    ClapTrap Juan2(Juan);
    ClapTrap Francois;

    Juan.attack("Pierre");
    Juan.takeDamage(9);
    Juan.beRepaired(4);
    Juan.takeDamage(3);
    Juan.takeDamage(3);

   Juan2.attack("Pierre");
   Juan2.takeDamage(9);
   Juan2.beRepaired(4);
   Juan2.takeDamage(3);
   Juan2.takeDamage(3);
   
   Francois.attack("Pierre");
   Francois.takeDamage(9);
   Francois.beRepaired(4);
   Francois.takeDamage(3);
   Francois.takeDamage(3);

    return EXIT_SUCCESS;
}

