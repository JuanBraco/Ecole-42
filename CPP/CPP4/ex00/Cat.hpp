#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

    public:

        Cat(void);
        Cat( const Cat &rhs );
        Cat &   operator=(Cat const & rhs);
        ~Cat();

        void            makeSound(void) const;
};

#endif