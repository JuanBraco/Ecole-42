#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>

class Fixed {

    public:

        Fixed();
        Fixed( const Fixed &rhs );
        Fixed &   operator=(Fixed const & rhs);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );

    private:

        int     _fixedPointValue;
        static const int _fract = 8;
};

#endif