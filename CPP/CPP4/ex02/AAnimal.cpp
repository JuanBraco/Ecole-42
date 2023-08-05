#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Animal constructor called" << std::endl;
	this->type = "Default";
}

AAnimal::~AAnimal()
{
	//std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &copy )
{
	type = copy.type;
}

AAnimal &AAnimal::operator=( const AAnimal &copy )
{
	std::cout << "AAnimal = called" << std::endl;
	if (this != &copy)
	{
		this->type = copy.type;
	}
	return *this;
}

void AAnimal::makeSound( void ) const
{
	std::cout << "*Pure silence*" << std::endl;
}

const std::string &AAnimal::getType( void ) const
{
	return (this->type);
}

std::ostream &operator<<( std::ostream &outStream, const AAnimal &Aanimal )
{
	outStream << "AAnimal: " << Aanimal.getType() << std::endl;
	return (outStream);
}
