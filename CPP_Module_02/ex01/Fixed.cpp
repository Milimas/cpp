#include "Fixed.hpp"

const int Fixed::fractionalBits = 8 ;

Fixed::Fixed( void ): value(0)
{
    std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed( const Fixed &fixed ): value(fixed.value)
{
    std::cout << "Copy constructor called" << std::endl ;
}

Fixed::Fixed( const int value ): value(value << Fixed::fractionalBits)
{
    std::cout << "int Constructor" << std::endl ;
}

Fixed::Fixed( const float value ): value(roundf(value * (1 << Fixed::fractionalBits)))
{
    std::cout << "float Constructor" << std::endl ;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl ;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl ;
    if (this != &other)
    {
        this->value = other.value ;
    }
    return (*this) ;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl ;
    return (this->value) ;
}

void Fixed::setRawBits( const int raw )
{
    std::cout << "setRawBits member function called" << std::endl ;
    this->value = raw ;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->value) / (1 << Fixed::fractionalBits));
}

int Fixed::toInt( void ) const
{
    return ((this->value) / (1 << Fixed::fractionalBits));
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj )
{
    os << obj.toFloat();
    return os;
}
