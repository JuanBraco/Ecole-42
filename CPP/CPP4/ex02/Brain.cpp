#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain class is born!" << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = "idea";
    return;
}

Brain::Brain( const Brain &rhs ) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
}

Brain &   Brain::operator=(Brain const & rhs) {
    std::cout << "Brain copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = rhs._ideas[i];
    }
    return *this;
}

Brain::~Brain(void) {
    std::cout << "Brain destructor called" << std::endl;
    return;
}

std::string    Brain::getIdea(unsigned int index) const {
    return (this->_ideas[index]);
}

void    Brain::setIdea(unsigned int index, std::string str) {
    this->_ideas[index] = str;
}

void    Brain::printAllIdeas(void) const {
    for (int i = 0; i < 100; i++)
        std::cout << this->_ideas[i] << std::endl;
}
