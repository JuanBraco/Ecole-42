#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>
#include "Brain.hpp"

class Animal {

    public:

        Animal(void);
        Animal( const Animal &rhs );
        virtual Animal &   operator=(Animal const & rhs);
        virtual ~Animal();

        const std::string    &getType( void ) const;
        virtual void            makeSound(void) const;
        virtual Brain *getBrain( void ) const = 0;

    protected:

        std::string type;
};

#endif