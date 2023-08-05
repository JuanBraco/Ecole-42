#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    //std::cout << type << "class is born!" << std::endl;
    return;
}

Ice::Ice( const Ice& rhs ) : AMateria()
{
    if (this != &rhs)
        this->type = rhs.type;
    *this = rhs;
}

Ice& Ice::operator=( const Ice& rhs )
{
    //std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Ice::~Ice(void) {
    //std::cout << "Ice destructor called"  << std::endl;
    return;
}

AMateria *Ice::clone( void ) const
{
	return (new Ice(*this));
}

void Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at "
		<< target.getName() << " *" << std::endl;
}
