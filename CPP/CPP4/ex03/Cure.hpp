#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

    public:

        Cure(void);
        Cure& operator=( const Cure& rhs );
        Cure( const Cure& rhs );
        virtual ~Cure();

        virtual AMateria    *clone( void ) const;
        virtual void        use( ICharacter &target );
    private:

};

#endif