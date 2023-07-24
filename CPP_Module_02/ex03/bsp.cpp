#include "Point.hpp"

Fixed   area( Point const a, Point const b, Point const c )
{
    Fixed ax = a.getX() ;
    Fixed bx = b.getX() ;
    Fixed cx = c.getX() ;
    Fixed ay = a.getY() ;
    Fixed by = b.getY() ;
    Fixed cy = c.getY() ;
    Fixed area = (ax*(by - cy) + bx*(cy-ay)+ cx*(ay-by)) / 2 ;
    return (Fixed::fAbs(area)) ;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area = ::area(a, b, c) ;
    Fixed area1 = ::area(a, b, point) ;
    Fixed area2 = ::area(a, point, c) ;
    Fixed area3 = ::area(point, b, c) ;

    return (area1 + area2 + area3 == area) ;
}