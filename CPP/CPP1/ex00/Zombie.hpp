#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Zombie {

    public:

        Zombie(std::string name);
        ~Zombie( void);

        void    announce(void);

    private:

        std::string _name;
};

#endif