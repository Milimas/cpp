#include "Fixed.hpp"

const int Fixed::fractionalBits = 8 ;

Fixed::Fixed( void ): value(0)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Fixed::Fixed( const Fixed& fixed ): value(fixed.value)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &other)
    {
        this->value = other.getRawBits() ;
    }
    return (*this) ;
}

Fixed::~Fixed( void )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

int Fixed::getRawBits( void ) const
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return (this->value) ;
}

void Fixed::setRawBits( const int raw )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    this->value = raw ;
}
