#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class WrongAnimal {

    public:

        WrongAnimal(void);
        WrongAnimal( const WrongAnimal &rhs );
        WrongAnimal &   operator=(WrongAnimal const & rhs);
        ~WrongAnimal();

        std::string    getType( void ) const;
        void            makeSound(void) const;

    protected:

        std::string type;
};

#endif