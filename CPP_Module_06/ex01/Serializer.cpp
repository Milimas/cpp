#include "Serializer.hpp"

Serializer::Serializer( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

Serializer::Serializer( const Serializer& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
}

Serializer& Serializer::operator=( const Serializer& other )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    (void)other ;
    return (*this) ;
}

Serializer::~Serializer( void )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
}

uintptr_t Serializer::serialize( Data* ptr )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    return ((uintptr_t)(void *)ptr) ;
}

Data* Serializer::deserialize( uintptr_t raw )
{
    std::cerr << __PRETTY_FUNCTION__ << std::endl ;
    return ((Data*)raw) ;
}