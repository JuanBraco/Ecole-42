#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        FragTrap();
        FragTrap(const std::string name);
        FragTrap( const FragTrap &rhs );
        FragTrap &   operator=(FragTrap const & rhs);
        ~FragTrap();

        void    highFivesGuys();
        void    attack(std::string const & target);
};

#endif