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



        Fixed   operator+(Fixed const & rhs) const;
        Fixed   operator-(Fixed const & rhs) const;
        Fixed   operator*(Fixed const & rhs) const;
        Fixed   operator/(Fixed const & rhs) const;
        bool    operator>( const Fixed &rhs ) const ;
        bool    operator<( const Fixed &rhs ) const ;
        bool    operator>=( const Fixed &rhs ) const ;
        bool    operator<=( const Fixed &rhs ) const ;
        bool    operator==( const Fixed &rhs ) const ;
        bool    operator!=( const Fixed &rhs ) const ;
        Fixed&  operator++( void );
        Fixed   operator++( int ); 
        Fixed&  operator--( void );
        Fixed   operator--( int ); 
        static Fixed& min( Fixed &a, Fixed &b );
        static const Fixed& min( const Fixed &a, const Fixed &b );
        static Fixed& max( Fixed &a, Fixed &b );
        static const Fixed& max( const Fixed &a, const Fixed &b );

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