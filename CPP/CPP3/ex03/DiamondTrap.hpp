#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
    public:
        DiamondTrap();
        DiamondTrap(const std::string name);
        DiamondTrap( const DiamondTrap &rhs );
        DiamondTrap &   operator=(DiamondTrap const & rhs);
        ~DiamondTrap();

        void attack( const std::string& target );
        void whoAmI();
    private:
        std::string _name;
};

#endif