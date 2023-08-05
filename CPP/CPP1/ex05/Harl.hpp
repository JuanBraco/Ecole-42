#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Harl {

    public:

        Harl(void);
        ~Harl( void);

        void complain( std::string level );

    private:

        void    debug( void );
        void    info( void );
        void    warning( void );
        void    error( void );
};

#endif