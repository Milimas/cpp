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
    Fixed( const Fixed &fixed ) ;
    Fixed& operator=( const Fixed& other ) ;
    ~Fixed( void ) ;
    
    int getRawBits( void ) const ;
    void setRawBits( const int raw ) ;
};

#endif