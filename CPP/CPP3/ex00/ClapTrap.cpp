#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap class " << "is born!" << std::endl;
    return;
}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap class " << _name << " is born!" << std::endl;
    return;
}

ClapTrap::ClapTrap( const ClapTrap &rhs ) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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
    std::cout << "ClapTrap the fight is over for you"  << std::endl;
    return;
}

void     ClapTrap::attack( const std::string& target ) {
    if (_hitPoints <= 0)
        return;
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
    _energyPoints -= 1;
}

void    ClapTrap::takeDamage( unsigned int amount )
{
    if (_hitPoints <= amount)
    {
        std::cout << "ClapTrap " << _name << " dies!" << std::endl;
        _hitPoints = 0;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    _hitPoints -= amount;
}

void    ClapTrap::beRepaired( unsigned int amount )
{
    if (_hitPoints <= 0)
        return;
    if (_energyPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    _energyPoints -= 1;
    _hitPoints += amount;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return (this->_attackDamage);
}

unsigned int	ClapTrap::getHitPoints() const
{
	return (this->_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return (this->_energyPoints);
}