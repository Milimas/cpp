#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 value ;
    static const int    fractional_bits = 8 ;

public:
    Fixed( void ) ;
    Fixed( const int value ) ;
    Fixed( const float value ) ;
    Fixed( const Fixed& fixed ) ;
    Fixed& operator=( const Fixed& other ) ;
    ~Fixed() ;

    bool operator>( const Fixed& other ) ;
    bool operator<( const Fixed& other ) ;
    bool operator>=( const Fixed& other ) ;
    bool operator<=( const Fixed& other ) ;
    bool operator==( const Fixed& other ) ;
    bool operator!=( const Fixed& other ) ;

    Fixed operator+( const Fixed& other ) ;
    Fixed operator-( const Fixed& other ) ;
    Fixed operator*( const Fixed& other ) ;
    Fixed operator/( const Fixed& other ) ;

    Fixed operator++( int ) ;
    Fixed operator--( int ) ;
    Fixed& operator++( void ) ;
    Fixed& operator--( void ) ;

    int getRawBits( void ) const ;
    void setRawBits( int const raw ) ;
    float toFloat( void ) const ;
    int toInt( void ) const ;

    static Fixed& min( Fixed& first, Fixed& second ) ;
    static const Fixed& min( const Fixed& first, const Fixed& second ) ;
    static Fixed& max( Fixed& first, Fixed& second ) ;
    static const Fixed& max( const Fixed& first, const Fixed& second ) ;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif