#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 value ;
    static const int    fraction = 8 ;
public:
    Fixed( void ) ;
    Fixed( Fixed &fixed ) ;
    Fixed& operator=( Fixed other ) ;
    ~Fixed() ;
    int getRawBits( void ) const ;
    void setRawBits( int const raw ) ;
};

#endif