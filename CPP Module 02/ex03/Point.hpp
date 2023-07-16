#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
    Fixed   x;
    Fixed   y;

public:
    Point( void ) ;
    Point( const Fixed x, const Fixed y ) ;
    Point( int x, int y ) ;
    Point( float x, float y ) ;
    Point( Point &point ) ;
    Point(Point const &Point);
    Point& operator=( Point other ) ;
    ~Point( void ) ;
    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

#endif