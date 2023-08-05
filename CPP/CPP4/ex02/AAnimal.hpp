#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>
#include "Brain.hpp"

class AAnimal {

    public:

        AAnimal(void);
        AAnimal( const AAnimal &copy );
        virtual AAnimal &   operator=(AAnimal const & rhs);
        virtual ~AAnimal();

        const std::string    &getType( void ) const;
        virtual void            makeSound(void) const;
        virtual Brain *getBrain( void ) const = 0;

    protected:

        std::string type;
};

#endif