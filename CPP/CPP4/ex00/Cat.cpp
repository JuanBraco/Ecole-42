#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) {
    this->type = "Cat";
    std::cout << type << "class is born!" << std::endl;
    return;
}

Cat::Cat( const Cat &rhs ) : Animal() {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Cat &   Cat::operator=(Cat const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

Cat::~Cat(void) {
    std::cout << "Cat destructor called"  << std::endl;
    return;
}

void    Cat::makeSound( void ) const
{
    std::cout << "Cat make sound" << std::endl;
}
