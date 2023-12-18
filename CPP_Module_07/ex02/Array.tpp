#include "Array.hpp"

#define RED "\e[31m"
#define NORMAL "\e[39m"

template <typename T>
Array<T>::Array( void ) : array(NULL), _size(0)
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
}

template <typename T>
Array<T>::Array( size_t n ) : array(new T[n]), _size(n)
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    for (size_t i = 0; i < _size; i++)
        array[i] = 0 ;
}

template <typename T>
Array<T>::Array( const Array& other) : _size(other._size)
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    array = new T[_size] ;
    for (size_t i = 0; i < _size; i++)
        array[i] = other.array[i] ;
}

template <typename T>
Array<T>& Array<T>::operator=( const Array<T>& other)
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    delete [] array ;
    _size = other._size ;
    array = new T[_size] ;
    for (size_t i = 0; i < _size; i++)
        array[i] = other.array[i] ;
    return (*this) ;
}

template <typename T>
T& Array<T>::operator[]( size_t index ) const
{
    if (index > size() - 1 )
        throw Array<T>::OutOfBoundException() ;
    return (array[index]) ;
}

template <typename T>
size_t  Array<T>::size( void ) const
{
    return (_size) ;
}

template <typename T>
Array<T>::~Array( void )
{
    std::cerr << RED << __PRETTY_FUNCTION__ << NORMAL << std::endl ;
    delete [] array ;
}

template <typename T>
std::ostream& operator<<( std::ostream& os, const Array<T>& array ) 
{
    for (size_t i = 0; i < array.size(); i++)
        os << "[" << i << "] = " << array[i] << std::endl ;
    return (os) ;
}
