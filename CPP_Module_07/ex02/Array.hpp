#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
private:
    T*      array ;
    size_t  _size ;
public:
    Array( void ) ;
    Array( size_t n ) ;
    Array( const Array& other ) ;
    Array& operator=( const Array& other ) ;
    ~Array( void ) ;

    T& operator[]( size_t index ) const ;

    size_t  size( void ) const ;

    class OutOfBoundException: public std::out_of_range
    {
    public:
		OutOfBoundException( void ) throw() 
            : out_of_range("Exception::OutOfBoundException") {} ;
        virtual ~OutOfBoundException( void ) throw() {} ;
    } ;
};

template <typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& array ) ;

#include "Array.tpp"

#endif