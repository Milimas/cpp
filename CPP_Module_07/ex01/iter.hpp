#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(T* array, size_t length, void (*fun)(T))
{
    for (size_t i = 0; i < length; i++)
        fun(array[i]);
}

template <typename T>
void    print( T elem )
{
    std::cout << elem << std::endl ;
}

#endif