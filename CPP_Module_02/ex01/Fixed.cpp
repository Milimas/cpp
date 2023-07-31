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

Fixed::Fixed( const int value ): value(value << Fixed::fractionalBits)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Fixed::Fixed( const float value ): value(roundf(value * (1 << Fixed::fractionalBits)))
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << __PRETTY_FUNCTION__ << std::endl ;
    if (this != &other)
    {
        this->value = other.value ;
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

float Fixed::toFloat( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return ((float)(this->value) / (1 << Fixed::fractionalBits));
}

int Fixed::toInt( void ) const
{
    // std::cout << __PRETTY_FUNCTION__ << std::endl ;
    return ((this->value) / (1 << Fixed::fractionalBits));
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj )
{
    os << obj.toFloat();
    return (os);
}
