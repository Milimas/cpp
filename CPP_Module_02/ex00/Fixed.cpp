#include "Fixed.hpp"

const int Fixed::fractionalBits = 8 ;

Fixed::Fixed( void ): value(0)
{
    std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed( const Fixed& fixed )
{
    std::cout << "Copy constructor called" << std::endl ;
    *this = fixed ;
}

Fixed& Fixed::operator=( const Fixed& other )
{
    std::cout << "Copy assignment operator called" << std::endl ;
    if (this != &other)
    {
        this->value = other.getRawBits() ;
    }
    return (*this) ;
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl ;
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
