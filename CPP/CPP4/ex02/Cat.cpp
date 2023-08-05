#include <iostream>
#include "Cat.hpp"

Cat::Cat()
	:AAnimal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->type = "Cat";

	this->_brain = new Brain();
}

Cat::~Cat()
{
	//std::cout << "Cat destructor called" << std::endl;

	delete this->_brain;
}

Cat::Cat( const Cat &copy )
	:AAnimal(copy)
{
	this->_brain = new Brain(*copy.getBrain());
}

Cat &Cat::operator=( const Cat &copy )
{
	if (this != &copy)
	{
		this->type = copy.getType();
		delete this->_brain;
		this->_brain = new Brain(*copy.getBrain());
	}
	return *this;
}

AAnimal	&Cat::operator=( const AAnimal &copy )
{
	if (this != &copy)
	{
		this->type = copy.getType();
		*(this->_brain) = *(copy.getBrain());
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Miao miao" << std::endl;
}

Brain	*Cat::getBrain( void ) const
{
	return (this->_brain);
}
