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
    Point( const Point &point );
    Point& operator=( const Point& other ) ;
    ~Point( void ) ;

    Point( int x, int y ) ;
    Point( float x, float y ) ;
    
    Fixed getX( void ) const;
    Fixed getY( void ) const;
};

#endif