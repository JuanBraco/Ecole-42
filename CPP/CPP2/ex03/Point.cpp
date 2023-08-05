#include <iostream>
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {
    //std::cout << "Point default constructor called"  << std::endl;
    return;
}

Point::Point(const float x, const float y ) : _x(x), _y(y) {
    //std::cout << "Point default constructor called"  << std::endl;
    return;
}

Point::Point( const Point &rhs ) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

Point &   Point::operator=(const Point & rhs) {
    //std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs) {
        (Fixed)this->_x = rhs.getX();
        (Fixed)this->_y = rhs.getY();
    }
    return *this;
}

Point::~Point(void) {
    //std::cout << "Destructor called" << std::endl;
    return;
}

Fixed     Point::getX(void) const {
    return this->_x;
}

Fixed     Point::getY(void) const {
    return this->_y;
}
