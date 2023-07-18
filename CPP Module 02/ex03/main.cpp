#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
    
    Point a(-1, 0) ;
    Point b(1, 0) ;
    Point c(0, 1) ;
    Point point(10, 0) ;

    std::cout << ::bsp(a, b, c, point) << std::endl ;
    return (0);
}