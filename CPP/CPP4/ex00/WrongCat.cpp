#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
    this->type = "WrongCat";
    std::cout << type << "class is born!" << std::endl;
    return;
}

WrongCat::WrongCat( const WrongCat &rhs ) :WrongAnimal(){
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

WrongCat &   WrongCat::operator=(WrongCat const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->type = rhs.type;
    }
    return *this;
}

WrongCat::~WrongCat(void) {
    std::cout << "WrongCat destructor called"  << std::endl;
    return;
}

void    WrongCat::makeSound( void ) const
{
    std::cout << "WrongCat make sound" << std::endl;
}
