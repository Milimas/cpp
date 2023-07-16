#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl ;
    this->value = 0 ;
}

Fixed::Fixed(Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl ;
    this->value = fixed.value ;
}

Fixed::Fixed(Fixed const &fixed)
{
    std::cout << "Copy constructor called" << std::endl ;
    this->value = fixed.value ;
}

Fixed::Fixed( const int value )
{
    std::cout << "Copy constructor called" << std::endl ;
    this->value = roundf(value * (1 << Fixed::fractional_bits)) ;
}

Fixed::Fixed( const float value )
{
    std::cout << "Copy constructor called" << std::endl ;
    this->value = roundf(value * (1 << Fixed::fractional_bits)) ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl ;
}

Fixed& Fixed::operator=(Fixed other)
{
    std::cout << "Copy assignment operator called" << std::endl ;
    if (this != &other)
    {
        this->value = other.value ;
    }
    return (*this) ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl ;
    return (this->value) ;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl ;
    this->value = roundf(raw * (1 << Fixed::fractional_bits)) ;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->value) / (float)(1 << Fixed::fractional_bits));
}

int Fixed::toInt( void ) const
{
    return ((this->value) / (1 << Fixed::fractional_bits));
}