#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    
    Point a(-1, 0) ;
    Point b(1, 0) ;
    Point c(0, 1) ;
    Point inside(0, 0) ;
    Point outside(10, 10) ;

    std::cout << "inside    " << ::bsp(a, b, c, inside) << std::endl ;
    std::cout << "outside   " << ::bsp(a, b, c, outside) << std::endl ;
    std::cout << "corner a  " << ::bsp(a, b, c, a) << std::endl ;
    std::cout << "corner b  " << ::bsp(a, b, c, b) << std::endl ;
    std::cout << "corner c  " << ::bsp(a, b, c, c) << std::endl ;

    return (0);
}