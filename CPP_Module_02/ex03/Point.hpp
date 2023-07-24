#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"
#include <iostream>

class Point
{
private:
    Fixed   x;
    Fixed   y;

public:
    Point( void ) ;
    Point( const Fixed x, const Fixed y ) ;
    Point( const Point &point );
    Point( int x, int y ) ;
    Point( float x, float y ) ;
    Point& operator=( const Point& other ) ;
    ~Point( void ) ;
    
    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

#endif