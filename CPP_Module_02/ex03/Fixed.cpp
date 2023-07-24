#include "Fixed.hpp"

Fixed::Fixed( void ): value(0) {
    std::cout << "bitset:" << std::bitset<16>(this->value) << " ==> " << value << std::endl ;
}

Fixed::Fixed( const Fixed& fixed ): value(fixed.value) {
    std::cout << "bitset:" << std::bitset<16>(this->value) << " ==> " << value << std::endl ;
}

Fixed::Fixed( const int value ): value((value << (Fixed::fractional_bits))) {
    std::cout << "bitset:" << std::bitset<16>(this->value) << " ==> " << value << std::endl ;
}

Fixed::Fixed( const float value ): value((int)(value * (1 << (Fixed::fractional_bits)))) {
    std::cout << "bitset:" << std::bitset<16>(this->value) << " ==> " << value << std::endl ;
}

Fixed::~Fixed() {}

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
    return ((float)(this->value) / (float)(1 << Fixed::fractional_bits)) ;
}

int Fixed::toInt( void ) const
{
    return ((this->value) / (1 << Fixed::fractional_bits)) ;
}

bool Fixed::operator>( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() > other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator>=( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() < other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator<( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() < other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

bool Fixed::operator<=( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() > other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator==( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() != other.getRawBits())
            return (false) ;
    }
    return (true) ;
}

bool Fixed::operator!=( const Fixed& other )
{
    if (this != &other)
    {
        if (this->getRawBits() != other.getRawBits())
            return (true) ;
    }
    return (false) ;
}

Fixed Fixed::operator+( const Fixed& other )
{
    return (Fixed(this->toFloat() + other.toFloat())) ;
}

Fixed Fixed::operator-( const Fixed& other )
{
    return (Fixed(this->toFloat() - other.toFloat())) ;
}

Fixed Fixed::operator*( const int& other ) const
{
    return (Fixed(this->toFloat() * other)) ;
}

Fixed Fixed::operator*( const Fixed& other )
{
    return (Fixed(this->toFloat() * other.toFloat())) ;
}

Fixed Fixed::operator/( const int& other )
{
    try
    {
        if (!other)
            throw std::runtime_error("Math error: Attempted to divide by Zero") ;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl ;
        return (*this);
    }
    return (Fixed(*this / (Fixed(other)))) ;
}

Fixed Fixed::operator/( const Fixed& other )
{
    try
    {
        if (!other.toInt())
            throw std::runtime_error("Math error: Attempted to divide by Zero") ;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl ;
        return (*this);
    }
    return ((float)((int)((long)(value << fractional_bits) / other.value)) / (float)(1 << fractional_bits)) ;
    // uint v2 = 1 ;
    // v2 <<= fractional_bits ;
    // v2 = (uint)(v2 / other.value) ;
    // int fp = value * v2 ;
    // fp <<= 1 ;
    // return (Fixed(fp)) ;
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

const Fixed Fixed::fAbs( const Fixed& number )
{
    if (number.toInt() < 0)
        return (number * -1) ;
    return (number) ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat() ;
    return (os) ;
}
