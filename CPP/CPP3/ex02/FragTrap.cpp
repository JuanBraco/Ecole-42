#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(void) {
    std::cout << "ScavTrap class is born!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap class is born!" << std::endl;
    return;
}

FragTrap::FragTrap( const FragTrap &rhs ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = rhs;
}

FragTrap &   FragTrap::operator=(FragTrap const & rhs) {
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

FragTrap::~FragTrap(void) {
    std::cout << "FragTrap destructor called"  << std::endl;
    return;
}

void FragTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0) {
        return;
    }
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " FragTrap can't attack because is dead" << std::endl;
		return;
	}
    std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
    this->_energyPoints -= 1;
}

void     FragTrap:: highFivesGuys( void ) {
        std::cout << this->_name << ": High Five Guys!" << std::endl;
        return;
}
