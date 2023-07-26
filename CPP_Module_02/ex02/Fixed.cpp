#include "Fixed.hpp"

const int Fixed::fractional_bits = 8 ;

Fixed::Fixed( void ): value(0) {}

Fixed::Fixed( const Fixed& fixed ): value(fixed.value) {}

Fixed::Fixed( const int value ): value(value << Fixed::fractional_bits) {}

Fixed::Fixed( const float value ): value(roundf(value * (1 << Fixed::fractional_bits))) {}

Fixed::~Fixed( void ) {}

Fixed& Fixed::operator=( const Fixed& other )
{
    if (this != &other)
    {
        this->value = other.value ;
    }
    return (*this) ;
}

int Fixed::getRawBits( void ) const
{
    return (this->value) ;
}

void Fixed::setRawBits( int const raw )
{
    this->value = raw ;
}

float Fixed::toFloat( void ) const
{
    return ((float)(this->value) / (1 << Fixed::fractional_bits)) ;
}

int Fixed::toInt( void ) const
{
    return (this->value / (1 << Fixed::fractional_bits)) ;
}

bool Fixed::operator>( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() > other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator>=( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() < other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator<( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() < other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator<=( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() > other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator==( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() != other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator!=( const Fixed& other ) const
{
    if (this != &other)
    {
        if (this->getRawBits() != other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

Fixed Fixed::operator+( const Fixed& other ) const
{
    Fixed res ;
    res.setRawBits(this->getRawBits() + other.getRawBits()) ;
    return (res) ;
}

Fixed Fixed::operator-( const Fixed& other ) const
{
    Fixed res ;
    res.setRawBits(this->getRawBits() - other.getRawBits()) ;
    return (res) ;
}

Fixed Fixed::operator*( const Fixed& other ) const
{
    return (Fixed(this->toFloat() * other.toFloat())) ;
}

Fixed Fixed::operator/( const Fixed& other ) const
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat() ;
    return (os) ;
}
