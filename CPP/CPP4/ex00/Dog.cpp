#include <iostream>
#include "Dog.hpp"

Dog::Dog(void) {
    this->type = "Dog";
    std::cout << type << "class is born!" << std::endl;
    return;
}

Dog::Dog( const Dog &rhs ) : Animal() {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Dog &   Dog::operator=(Dog const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Dog::~Dog(void) {
    std::cout << "Dog destructor called"  << std::endl;
    return;
}

void    Dog::makeSound( void ) const
{
    std::cout << "Dog make sound" << std::endl;
}
