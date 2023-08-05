#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Weapon {

    public:

        Weapon(std::string type);
        ~Weapon( void);

        const std::string&    getType(void);
        void    setType(std::string name);

    private:

        std::string _type;
};


#endif