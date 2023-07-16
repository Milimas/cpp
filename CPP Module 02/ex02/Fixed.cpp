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
    os << obj.toFloat() ;
    return os ;
}


int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl ;
    return (this->value) ;
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl ;
    this->value = raw ;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->value) / (float)(1 << Fixed::fractional_bits)) ;
}

int Fixed::toInt( void ) const
{
    return ((this->value) / (1 << Fixed::fractional_bits)) ;
}

bool Fixed::operator>(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() > other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator>=(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() >= other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator<(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() < other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator<=(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() <= other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator==(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() != other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator!=(Fixed other)
{
    if (this != &other)
    {
        if (this->getRawBits() == other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

Fixed Fixed::operator+(Fixed other)
{
    return (Fixed(this->toFloat() + other.toFloat())) ;
}

Fixed Fixed::operator-(Fixed other)
{
    return (Fixed(this->toFloat() - other.toFloat())) ;
}

Fixed Fixed::operator*(Fixed other)
{
    return (Fixed(this->toFloat() * other.toFloat())) ;
}

Fixed Fixed::operator/(Fixed other)
{
    return (Fixed(this->toFloat() / other.toFloat())) ;
}

Fixed Fixed::operator++( int )
{
    Fixed tmp = *this;
    value++ ;
    return (tmp) ;
}

Fixed Fixed::operator--( int )
{
    Fixed tmp = *this;
    value-- ;
    return (tmp) ;
}

Fixed& Fixed::operator++( void )
{
    value++ ;
    return (*this) ;
}

Fixed& Fixed::operator--( void )
{
    value-- ;
    return (*this) ;
}

Fixed& Fixed::min( Fixed& first, Fixed& second )
{
    if ( first > second )
        return (second) ;
    return (first) ;
}


const Fixed& Fixed::min( const Fixed& first, const Fixed& second )
{
    if ( (Fixed)first > (Fixed)second )
        return (second);
    return (first) ;
}


Fixed& Fixed::max( Fixed& first, Fixed& second )
{
    if ( first < second )
        return (second) ;
    return (first) ;
}


const Fixed& Fixed::max( const Fixed& first, const Fixed& second )
{
    if ( (Fixed)first < (Fixed)second )
        return (second);
    return (first) ;
}