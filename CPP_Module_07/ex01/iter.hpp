#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void    iter(const T* array, size_t length, void (*fun)(T))
{
    if (!array || !fun)
        return ;
    for (size_t i = 0; (int)i < (int)length; i++)
        fun(array[i]);
}

template <typename T>
void    print( T elem )
{
    std::cout << elem << std::endl ;
}

#endif