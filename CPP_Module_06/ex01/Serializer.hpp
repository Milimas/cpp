#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

/* Types for `void *' pointers.  */
#if __WORDSIZE == 64
typedef unsigned long int        uintptr_t;
#else
typedef unsigned int                uintptr_t;
#endif

class Serializer
{
private:
    Serializer( void ) ;
    Serializer( const Serializer& other ) ;
    Serializer& operator=( const Serializer& other ) ;
    ~Serializer( void ) ;
public:
    static uintptr_t serialize( Data* ptr ) ;
    static Data* deserialize( uintptr_t raw ) ;
};

#endif
