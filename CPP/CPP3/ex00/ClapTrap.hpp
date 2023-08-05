#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class ClapTrap {

    public:

        ClapTrap();
        ClapTrap(const std::string name);
        ClapTrap( const ClapTrap &rhs );
        ClapTrap &   operator=(ClapTrap const & rhs);
        ~ClapTrap();

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );
        unsigned int	getAttackDamage() const;
		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;

    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif