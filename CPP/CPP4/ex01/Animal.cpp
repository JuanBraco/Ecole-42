#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Default";
}

Animal::~Animal()
{
	//std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal( const Animal &copy )
{
	type = copy.type;
}

Animal &Animal::operator=( const Animal &copy )
{
	std::cout << "Animal = called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void Animal::makeSound( void ) const
{
	std::cout << "*Pure silence*" << std::endl;
}

const std::string &Animal::getType( void ) const
{
	return (this->type);
}

std::ostream &operator<<( std::ostream &outStream, const Animal &animal )
{
	outStream << "Animal: " << animal.getType() << std::endl;
	return (outStream);
}
