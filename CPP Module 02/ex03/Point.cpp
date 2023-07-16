#include "Point.hpp"

Point::Point(void)
{
    this->x = Fixed(0) ;
    this->y = Fixed(0) ;
}

Point::Point( const Fixed x, const Fixed y )
{
    this->x = x;
    this->y = y;
}

Point::Point( int x, int y )
{
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point( float x, float y )
{
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point(Point &Point)
{
    this->x = Point.x ;
    this->y = Point.y ;
}

Point::Point(Point const &Point)
{
    this->x = Point.x ;
    this->y = Point.y ;
}


Point::~Point()
{
}

Point& Point::operator=(Point other)
{
    if (this != &other)
    {
        this->x = other.x ;
        this->y = other.y ;
    }
    return (*this) ;
}

Fixed Point::getX( void ) const
{
    return (this->x) ;
}

Fixed Point::getY( void ) const
{
    return (this->y) ;
}