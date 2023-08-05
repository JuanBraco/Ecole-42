#include <iostream>
#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
    std::cout << "Animal class " << type << " is born!" << std::endl;
    return;
}

Animal::Animal( const Animal &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Animal &   Animal::operator=(Animal const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called"  << std::endl;
    return;
}

std::string    Animal::getType( void ) const
{
    return this->type;
}

void    Animal::makeSound( void ) const
{
    std::cout << "Animal make sound" << std::endl;
}
