#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Zombie {

    public:

        Zombie(void);
        ~Zombie( void);

        void    announce(void);
        void    setName(std::string name);

    private:

        std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif