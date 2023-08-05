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
        virtual ~ClapTrap();

        void attack( const std::string& target );
        void takeDamage( unsigned int amount );
        void beRepaired( unsigned int amount );

    protected:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
};

#endif