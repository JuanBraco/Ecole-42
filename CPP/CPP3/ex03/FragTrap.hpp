#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string name);
        FragTrap( const FragTrap &rhs );
        FragTrap &   operator=(FragTrap const & rhs);
        virtual ~FragTrap();

        void  highFivesGuys();
        virtual void    attack(std::string const & target);

        virtual void	setHitPoints(void);
		virtual void	setEnergyPoints(void);
		virtual void	setAttackDamage(void);
};

#endif