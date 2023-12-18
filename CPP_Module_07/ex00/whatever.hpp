#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

#define RED "\e[31m"
#define NORMAL "\e[39m"

template <typename T>
void    swap( T &a, T &b )
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    T tmp ;

    tmp = a ;
    a = b ;
    b = tmp ;
}

template <typename T>
const T& min( const T& a, const T& b )
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    if (a < b)
        return (a) ;
    return (b) ;
}

template <typename T>
const T& max( const T& a, const T& b )
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    if (a > b)
        return (a) ;
    return (b) ;
}

#endif