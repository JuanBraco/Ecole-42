#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const std::string name);
        ScavTrap( const ScavTrap &rhs );
        ScavTrap &   operator=(ScavTrap const & rhs);
        ~ScavTrap();

        virtual void attack( const std::string& target );
        void guardGate();

        virtual void	setHitPoints(void);
		virtual void	setEnergyPoints(void);
		virtual void	setAttackDamage(void);
};

#endif