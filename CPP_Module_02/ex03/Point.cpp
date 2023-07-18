#include "Point.hpp"

Point::Point(void): x(0), y(0)
{
}

Point::Point( const Fixed x, const Fixed y ): x(x), y(y)
{
}

Point::Point( int x, int y ): x(x), y(y)
{
}

Point::Point( float x, float y ): x(x), y(y)
{
}

Point::Point( const Point& point ): x(point.x), y(point.y)
{
}

Point::~Point()
{
}

Point& Point::operator=( const Point& other )
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