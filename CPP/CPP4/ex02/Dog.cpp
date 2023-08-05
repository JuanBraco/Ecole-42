#include <iostream>
#include "Dog.hpp"

Dog::Dog()
	:AAnimal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = "Dog";

	this->_brain = new Brain();
}

Dog::~Dog()
{
	//std::cout << "Dog destructor called" << std::endl;

	delete this->_brain;
}

Dog::Dog( const Dog &copy )
	:AAnimal(copy)
{
	*this = copy;
}

Dog &Dog::operator=( const Dog &copy )
{
	std::cout << "Dog = called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.getType();
		delete this->_brain;
		this->_brain = new Brain(*copy.getBrain());
	}
	return *this;
}

AAnimal	&Dog::operator=( const AAnimal &copy )
{
	if (this != &copy)
	{
		this->type = copy.getType();
		*(this->_brain) = *(copy.getBrain());
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Dog make sound" << std::endl;
}

Brain	*Dog::getBrain( void ) const
{
	return (this->_brain);
}
