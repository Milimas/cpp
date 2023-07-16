#include "Point.hpp"

float   area( Point const a, Point const b, Point const c )
{
    float ax = a.getX().toFloat();
    float bx = b.getX().toFloat();
    float cx = c.getX().toFloat();
    float ay = a.getY().toFloat();
    float by = b.getY().toFloat();
    float cy = c.getY().toFloat();
    float area = (float)(ax*(by - cy) + bx*(cy-ay)+ cx*(ay-by)) / 2.0f ;
    if (area < 0)
        area = area * -1;
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float area = ::area(a, b, c) ;
    float area1 = ::area(a, b, point) ;
    float area2 = ::area(a, point, c) ;
    float area3 = ::area(point, b, c) ;

    return (area1 + area2 + area3 == area) ;
}