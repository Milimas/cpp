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
    Fixed( const Fixed& fixed ) ;
    Fixed& operator=( const Fixed& other ) ;
    ~Fixed( void ) ;

    Fixed( const int value ) ;
    Fixed( const float value ) ;

    bool operator>( const Fixed& other ) const ;
    bool operator<( const Fixed& other ) const ;
    bool operator>=( const Fixed& other ) const ;
    bool operator<=( const Fixed& other ) const ;
    bool operator==( const Fixed& other ) const ;
    bool operator!=( const Fixed& other ) const ;

    Fixed operator+( const Fixed& other ) const ;
    Fixed operator-( const Fixed& other ) const ;
    Fixed operator*( const Fixed& other ) const ;
    Fixed operator/( const Fixed& other ) const ;

    Fixed operator++( int ) ;
    Fixed operator--( int ) ;
    Fixed& operator++( void ) ;
    Fixed& operator--( void ) ;

    int getRawBits( void ) const ;
    void setRawBits( const int raw ) ;
    float toFloat( void ) const ;
    int toInt( void ) const ;

    static Fixed& min( Fixed& first, Fixed& second ) ;
    static const Fixed& min( const Fixed& first, const Fixed& second ) ;
    static Fixed& max( Fixed& first, Fixed& second ) ;
    static const Fixed& max( const Fixed& first, const Fixed& second ) ;
};

std::ostream& operator<<( std::ostream& os, const Fixed& obj );

#endif