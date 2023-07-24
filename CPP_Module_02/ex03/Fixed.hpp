#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <bitset>
#include <sstream>

class Fixed
{
private:
    uint                 value ;
    static const int    fractional_bits = 2 ;

public:
    Fixed( void ) ;
    Fixed( const int value ) ;
    Fixed( const float value ) ;
    Fixed( const Fixed& fixed ) ;
    Fixed& operator=( const Fixed& other ) ;

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
    Fixed operator()( const Fixed& other ) ;

    Fixed operator*( const int& other ) const ;
    Fixed operator/( const int& other ) ;

    Fixed operator++( int ) ;
    Fixed operator--( int ) ;
    Fixed& operator++( void ) ;
    Fixed& operator--( void ) ;

    ~Fixed() ;
    int getRawBits( void ) const ;
    void setRawBits( int const raw ) ;
    float toFloat( void ) const ;
    int toInt( void ) const ;

    static Fixed& min( Fixed& first, Fixed& second ) ;
    static const Fixed& min( const Fixed& first, const Fixed& second ) ;
    static Fixed& max( Fixed& first, Fixed& second ) ;
    static const Fixed& max( const Fixed& first, const Fixed& second ) ;
    static const Fixed fAbs( const Fixed& number ) ;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif