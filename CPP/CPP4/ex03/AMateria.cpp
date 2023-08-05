#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : type("AMateria") {
    //std::cout << "AMateria class " << type << " is born!" << std::endl;
    return;
}

AMateria::AMateria( const std::string &type )
	: type(type)
{
	//std::cout << "String constructor for AMateria called" << std::endl;
	return;
}

AMateria::AMateria( const AMateria &rhs ) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

AMateria &   AMateria::operator=(AMateria const & rhs) {
    //std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return *this;
}

AMateria::~AMateria(void) {
    //std::cout << "AMateria destructor called"  << std::endl;
    return;
}

std::string const & AMateria::getType( void ) const
{
    return this->type;
}
