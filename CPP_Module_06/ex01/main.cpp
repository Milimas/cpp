#include "Serializer.hpp"

int main( void )
{
    Data f;

    f.number = 1337 ;
    std::cout << (&f == Serializer::deserialize(Serializer::serialize(&f))) << std::endl ;
    return (0) ;
}