#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    //std::cout << type << "class is born!" << std::endl;
    return;
}

Cure::Cure( const Cure& rhs ) : AMateria()
{
    if (this != &rhs)
        this->type = rhs.type;
    *this = rhs;
}

Cure& Cure::operator=( const Cure& rhs )
{
    //std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Cure::~Cure(void) {
    //std::cout << "Cure destructor called"  << std::endl;
    return;
}

AMateria *Cure::clone( void ) const
{
	return (new Cure(*this));
}

void Cure::use( ICharacter &target )
{
    std::cout << "* heals "
		<< target.getName() << "’s wounds *" << std::endl;
}
