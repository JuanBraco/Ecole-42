#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Wronganimal") {
    std::cout << "WrongAnimal class " << type << " is born!" << std::endl;
    return;
}

WrongAnimal::WrongAnimal( const WrongAnimal &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

WrongAnimal &   WrongAnimal::operator=(WrongAnimal const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal(void) {
    std::cout << "WrongAnimal destructor called"  << std::endl;
    return;
}

std::string    WrongAnimal::getType( void ) const
{
    return this->type;
}

void    WrongAnimal::makeSound( void ) const
{
    std::cout << "WrongAnimal make sound" << std::endl;
}
