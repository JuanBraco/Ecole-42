#include "Fixed.hpp"

Fixed::Fixed(void) {
    std::cout << "Default constructor called"  << std::endl;
    this->_fixedPointValue = 0;
    return;
}

Fixed::Fixed( const Fixed &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed &   Fixed::operator=(const Fixed & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called"  << std::endl;
    return;
}

int     Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void    Fixed::setRawBits( int const raw ) {
    this->_fixedPointValue = raw;
}
