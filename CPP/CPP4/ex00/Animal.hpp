#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Animal {

    public:

        Animal(void);
        Animal( const Animal &rhs );
        Animal &   operator=(Animal const & rhs);
        virtual ~Animal();

        std::string    getType( void ) const;
        virtual void            makeSound(void) const;

    protected:

        std::string type;
};

#endif