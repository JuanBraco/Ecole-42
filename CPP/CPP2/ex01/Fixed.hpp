#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include <iostream>
# include <cmath>

class Fixed {

    public:

        Fixed();
        Fixed( const int n );
        Fixed( const float n );
        Fixed( const Fixed &rhs );
        Fixed &   operator=(Fixed const & rhs);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

    private:

        int     _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif