#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    // Point a(-1, 0) ;
    // Point b(1, 0) ;
    // Point c(0, 1) ;
    // Point inside(0, 0) ;
    // Point outside(10, 10) ;

    // std::cout << "inside    " << ::bsp(a, b, c, inside) << std::endl ;
    // std::cout << "outside   " << ::bsp(a, b, c, outside) << std::endl ;
    // std::cout << "corner a  " << ::bsp(a, b, c, a) << std::endl ;
    // std::cout << "corner b  " << ::bsp(a, b, c, b) << std::endl ;
    // std::cout << "corner c  " << ::bsp(a, b, c, c) << std::endl ;

    Fixed zero(12.75f) ;
    std::cout << zero << std::endl ;
    // Fixed one(1) ;
    // Fixed three(2.5f) ;

    // one = one / three;
    // std::cout << one << " / " << three << ": " << one / three << std::endl ;
    // std::cout << one << " / " << three << ": " << one.toFloat() / three.toFloat() << std::endl ;
    // std::cout << 1.0f << " / " << 3.0f << ": " << 1.0f / 3.0f << std::endl ;

    // one = one / 0 ;
    // one = one / zero ;
    // one = one / 2 ;

    // std::cout << one << std::endl ;
    // std::cout << zero << std::endl ;

    return (0);
}