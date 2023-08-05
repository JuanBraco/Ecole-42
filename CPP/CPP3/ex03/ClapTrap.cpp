#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap class is born!" << std::endl;
    return;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap class " << this->_name << " is born!" << std::endl;
    return;
}

ClapTrap::ClapTrap( const ClapTrap &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

ClapTrap &   ClapTrap::operator=(ClapTrap const & rhs) {
    std::cout << "Copy assignation operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap destructor called"  << std::endl;
    return;
}

void     ClapTrap::attack( const std::string& target ) {
    if (_hitPoints <= 0)
        return;
    if (this->_energyPoints <= 0)
    {
        std::cout << this->_name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
    this->_energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (_hitPoints <= amount)
    {
        std::cout << _name << " is dead!" << std::endl;
        _hitPoints = 0;
        return;
    }
    std::cout << _name << " takes " << amount << " damage!" << std::endl;
    _hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (_hitPoints <= 0)
        return;
    if (_energyPoints <= 0)
    {
        std::cout << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    _energyPoints -= 1;
    _hitPoints += amount;
}
