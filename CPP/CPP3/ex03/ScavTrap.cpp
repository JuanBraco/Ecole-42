#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
    std::cout << "ScavTrap class is born!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return;
}

ScavTrap::ScavTrap(const std::string name) {
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap class " << _name << " is born!" << std::endl;
    return;
}

ScavTrap::ScavTrap( const ScavTrap &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

ScavTrap &   ScavTrap::operator=(ScavTrap const & rhs) {
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

ScavTrap::~ScavTrap(void) {
    std::cout << "ScavTrap destructor called"  << std::endl;
    return;
}

void     ScavTrap::attack( const std::string& target ) {
    if (_hitPoints <= 0)
        return;
    if (this->_energyPoints <= 0)
    {
        std::cout << this->_name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ScavTrap attack " << target << ", causing " << _attackDamage << " points of damage" << std::endl;
    this->_energyPoints -= 1;
}

void     ScavTrap::guardGate( void ) {
        std::cout << "ScavTrap " << this->_name << "is in Gate keeper mode" << std::endl;
        return;
}

void		ScavTrap::setHitPoints(void)    { this->_hitPoints = 100; }
void		ScavTrap::setEnergyPoints(void) { this->_energyPoints = 50; }
void		ScavTrap::setAttackDamage(void) { this->_attackDamage = 20; }
