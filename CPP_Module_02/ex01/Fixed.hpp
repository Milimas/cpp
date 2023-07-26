#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 value ;
    static const int    fractionalBits ;
public:
    Fixed( void ) ;
    Fixed( const int value ) ;
    Fixed( const float value ) ;
    Fixed( const Fixed &fixed ) ;
    Fixed& operator=( const Fixed& other ) ;
    ~Fixed( void ) ;
    int getRawBits( void ) const ;
    void setRawBits( const int raw ) ;
    float toFloat( void ) const ;
    int toInt( void ) const ;
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif