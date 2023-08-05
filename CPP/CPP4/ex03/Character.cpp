#include <iostream>
#include "Character.hpp"

Character::Character(void) :_name("") {
    this->_NbItems = 0;
    //std::cout << "Character class is born!" << std::endl;
	for (size_t i = 0; i < Character::_inventorySize; i++)
		_inventory[i] = NULL;
}

Character::Character( std::string const &name )
{
	*this = Character();
	_name = name;
}

Character::Character( const Character &copy ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Character &   Character::operator=(Character const & rhs) {
	_NbItems = 0;
	for (int i = 0; i < Character::_inventorySize; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = rhs._inventory[i];
		if (rhs._inventory[i])
			_NbItems++;
	}
	_name = rhs.getName();
	return *this;
}

Character::~Character(void) {
    //std::cout << "Character destructor called" << std::endl;
	//std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < Character::_inventorySize; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const &Character::getName( void ) const
{
	return (_name);
}

void Character::equip( AMateria *m )
{
	if (_NbItems == Character::_inventorySize)
	{
		/*std::cout << "Inventory full" << std::endl;*/
		return;
	}

	int i = 0;
	while (_inventory[i] != NULL)
		i++;
	_inventory[i] = m;
	_NbItems++;
	/*std::cout << this->_name << " equipped a "
		<< m->getType() << std::endl;*/
}

void Character::unequip( int idx )
{
	if (idx < 0 || idx >= Character::_inventorySize)
	{
		/*std::cout << "Wrong index" << std::endl;*/
		return;
	}

	if (_NbItems == 0 || _inventory[idx] == NULL)
	{
		/*std::cout << "Inventory spot empty" << std::endl;*/
		return;
	}

	/*std::cout << _name << " dropped a "
		<< _inventory[idx]->getType() << std::endl;*/
	_NbItems--;
	_inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter &target )
{
	if (idx < 0 || idx > Character::_inventorySize)
		return;
	_inventory[idx]->use(target);
	this->unequip(idx);
}