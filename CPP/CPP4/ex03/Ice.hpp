#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

    public:

        Ice(void);
        Ice& operator=( const Ice& rhs );
        Ice( const Ice& rhs );
        virtual ~Ice();

        virtual AMateria    *clone( void ) const;
        void use( ICharacter &target );

    
    private:

        
};

#endif