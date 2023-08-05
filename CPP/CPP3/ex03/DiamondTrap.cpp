#include <iostream>
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :
    ClapTrap(),
	FragTrap(),
	ScavTrap(),
    _name("") {
    ClapTrap::_name = "_clap_name";
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap class is born!" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name) {
	this->FragTrap::setHitPoints();
	this->ScavTrap::setEnergyPoints();
	this->FragTrap::setAttackDamage();
    std::cout << "DiamondTrap class " << _name << " is born!" << std::endl;
    return;
}

DiamondTrap &		DiamondTrap::operator=(const DiamondTrap &ref) {
	
	if (this == &ref)
		return *this;
	
	this->_name = ref._name;
	this->ClapTrap::_name = ref._name + "_clap_name";
	this->_hitPoints = ref._hitPoints;
	this->_energyPoints = ref._energyPoints;
	this->_attackDamage = ref._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap(void) {
    std::cout << "DiamondTrap destructor called"  << std::endl;
    return;
}

void     DiamondTrap::attack( const std::string& target ) {
    this->ScavTrap::attack(target);
}

void     DiamondTrap::whoAmI( void ) {
        std::cout << "DiamondTrap name : " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
        return;
}
