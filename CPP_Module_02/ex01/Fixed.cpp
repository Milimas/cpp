#include "Fixed.hpp"

Fixed::Fixed( void ): value(0)
{
    std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed( const Fixed &fixed ): value(fixed.value)
{
    std::cout << "Copy constructor called" << std::endl ;
}

Fixed::Fixed( const int value ): value(roundf(value * (1 << Fixed::fractional_bits)))
{
    std::cout << "int Constructor" << std::endl ;
}

Fixed::Fixed( const float value ): value(roundf(value * (1 << Fixed::fractional_bits)))
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
    this->value = roundf(raw * (1 << Fixed::fractional_bits)) ;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->value) / (1 << Fixed::fractional_bits));
}

int Fixed::toInt( void ) const
{
    return ((this->value) / (1 << Fixed::fractional_bits));
}

std::ostream& operator<<( std::ostream& os, const Fixed& obj )
{
    os << obj.toFloat();
    return os;
}
