#include "Point.hpp"

Fixed   area( Point const a, Point const b, Point const c )
{
    Fixed ax = a.getX().toFloat() ;
    Fixed bx = b.getX().toFloat() ;
    Fixed cx = c.getX().toFloat() ;
    Fixed ay = a.getY().toFloat() ;
    Fixed by = b.getY().toFloat() ;
    Fixed cy = c.getY().toFloat() ;
    Fixed area = (ax*(by - cy) + bx*(cy-ay)+ cx*(ay-by)) / Fixed(2.0f) ;
    if (area < 0)
        area = area * -1 ;
    return (area) ;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area = ::area(a, b, c) ;
    Fixed area1 = ::area(a, b, point) ;
    Fixed area2 = ::area(a, point, c) ;
    Fixed area3 = ::area(point, b, c) ;

    return (area1 + area2 + area3 == area) ;
}